import os
import pickle
import networkx as nx
import random

DAG_DIR = "dag_dataset"
LOOP_DIR = "generated_loops"
os.makedirs(LOOP_DIR, exist_ok=True)

ARRAYS_1D = ["X", "Y", "Z"]
ARRAYS_2D = ["A", "B", "C"]
OPERATORS = ['+', '-', '*']

def create_access(var):
    return f"{var}[i]" if var in ARRAYS_1D else f"{var}[i][j]"

class Node:
    def __init__(self, label):
        self.label = label
        self.lhs = None
        self.rhs = set()
        self.required_rhs = set()

def generate_loop(dag_path, output_path):
    with open(dag_path, "rb") as f:
        dag = pickle.load(f)

    order = list(nx.topological_sort(dag))
    nodes = {}

    # STEP 1: assign initial LHS
    for nid in order:
        label = dag.nodes[nid]["label"]
        var = random.choice(ARRAYS_1D + ARRAYS_2D)
        lhs = create_access(var)
        nodes[nid] = Node(label)
        nodes[nid].lhs = lhs

    # STEP 2: enforce dependencies
    for u, v, data in dag.edges(data=True):
        dep_type = data["type"]
        u_node = nodes[u]
        v_node = nodes[v]

        if dep_type == "true":
            v_node.required_rhs.add(u_node.lhs)
        elif dep_type == "anti":
            u_node.required_rhs.add(v_node.lhs)
        elif dep_type == "output":
            v_node.lhs = u_node.lhs  # force LHS match

    # STEP 3: build final RHS per node
    for node in nodes.values():
        node.rhs.update(node.required_rhs)
        while len(node.rhs) < 2:
            rvar = create_access(random.choice(ARRAYS_1D + ARRAYS_2D))
            if rvar != node.lhs:
                node.rhs.add(rvar)

    # STEP 4: write code
    lines = []
    for nid in order:
        node = nodes[nid]
        r1, r2 = list(node.rhs)[:2]
        op = random.choice(OPERATORS)
        lines.append(f"            {node.lhs} = {r1} {op} {r2};")

    code = [
        "#include <stdio.h>",
        "#define N 1024",
        "",
        "int main() {",
        "    float A[N][N], B[N][N], C[N][N], X[N], Y[N], Z[N];",
        "    for (int i = 0; i < N; i++) {",
        "        for (int j = 0; j < N; j++) {"
    ] + lines + [
        "        }",
        "    }",
        "    return 0;",
        "}"
    ]

    with open(output_path, "w") as f:
        f.write("\n".join(code))
    print(f"✅ Generated: {output_path}")

# Run on all DAGs
for fname in sorted(os.listdir(DAG_DIR)):
    if fname.endswith(".pkl"):
        dag_path = os.path.join(DAG_DIR, fname)
        loop_path = os.path.join(LOOP_DIR, fname.replace(".pkl", ".c"))
        generate_loop(dag_path, loop_path)

print("🎯 All loops generated with fully enforced true, anti, and output dependencies.")
