import random
import networkx as nx
import os
import pickle
import csv

# Configurable parameters
NUM_DAGS = 100
DEPENDENCY_TYPES = ['true', 'anti', 'output']
SAVE_DIR = "dag_dataset"
LOOP_DIR = "generated_loops"
FEATURE_FILE = "loop_features.csv"

os.makedirs(SAVE_DIR, exist_ok=True)
os.makedirs(LOOP_DIR, exist_ok=True)

features = []

for dag_id in range(NUM_DAGS):
    num_nodes = random.randint(6, 10)
    dag = nx.DiGraph()

    for i in range(num_nodes):
        dag.add_node(i, label=f'S{i+1}')

    added_edges = 0
    max_edges = num_nodes * 2
    while added_edges < max_edges:
        src = random.randint(0, num_nodes - 2)
        dst = random.randint(src + 1, num_nodes - 1)
        if not dag.has_edge(src, dst):
            dep_type = random.choice(DEPENDENCY_TYPES)
            dag.add_edge(src, dst, type=dep_type)
            added_edges += 1

    dag_filename = os.path.join(SAVE_DIR, f"loop_dag_{dag_id}.pkl")
    with open(dag_filename, "wb") as f:
        pickle.dump(dag, f)

    # Generate C code
    ordered_nodes = list(nx.topological_sort(dag))
    code_lines = [
        "#include <stdio.h>",
        "#define N 1024",
        "",
        "int main() {",
        "    float A[N][N], B[N][N], C[N][N], X[N], Y[N], Z[N];",
        "",
        "    for (int i = 0; i < N; i++) {",
        "        for (int j = 0; j < N; j++) {"
    ]

    feat = {
        "dag_id": dag_id,
        "num_A_fi_gj": 0,
        "num_A_fj_gi": 0,
        "num_X_fi": 0,
        "num_X_fj": 0,
        "num_2D_arrays": 0,
        "num_1D_arrays": 0,
        "par_i": 1,
        "par_j": 0,
        "problem_size": 1024,

        # Structural features
        "num_nodes": dag.number_of_nodes(),
        "num_edges": dag.number_of_edges(),
        "avg_degree": sum(dict(dag.degree()).values()) / dag.number_of_nodes(),
        "num_roots": len([n for n in dag.nodes if dag.in_degree(n) == 0]),
        "num_leaves": len([n for n in dag.nodes if dag.out_degree(n) == 0]),
        "depth": nx.dag_longest_path_length(dag) + 1 if nx.is_directed_acyclic_graph(dag) else 1,
        "num_true_deps": sum(1 for _, _, d in dag.edges(data=True) if d['type'] == 'true'),
        "num_anti_deps": sum(1 for _, _, d in dag.edges(data=True) if d['type'] == 'anti'),
        "num_output_deps": sum(1 for _, _, d in dag.edges(data=True) if d['type'] == 'output'),
        "density": nx.density(dag)
    }

    for node in ordered_nodes:
        lhs = random.choice(["A[i][j]", "B[i][j]", "C[i][j]", "X[i]", "Y[j]", "Z[i]"])
        rhs1 = random.choice(["A[i][j]", "B[i][j]", "C[i][j]", "X[i]", "Y[j]", "Z[i]"])
        rhs2 = random.choice(["A[i][j]", "B[i][j]", "C[i][j]", "X[i]", "Y[j]", "Z[i]"])
        op = random.choice(['+', '-', '*'])
        stmt = f"            {lhs} = {rhs1} {op} {rhs2};"
        code_lines.append(stmt)

        for ref in [lhs, rhs1, rhs2]:
            if ref.endswith("[i][j]"):
                feat["num_A_fi_gj"] += 1
                feat["num_2D_arrays"] += 1
            elif ref.endswith("[j][i]"):
                feat["num_A_fj_gi"] += 1
                feat["num_2D_arrays"] += 1
            elif ref.endswith("[i]"):
                feat["num_X_fi"] += 1
                feat["num_1D_arrays"] += 1
            elif ref.endswith("[j]"):
                feat["num_X_fj"] += 1
                feat["num_1D_arrays"] += 1

    code_lines.extend(["        }", "    }", "    return 0;", "}"])

    loop_filename = os.path.join(LOOP_DIR, f"loop_code_{dag_id}.c")
    with open(loop_filename, "w") as f:
        f.write("\n".join(code_lines))

    features.append(feat)
    print(f"✅ DAG {dag_id+1}/{NUM_DAGS} saved")

# Save features to CSV
with open(FEATURE_FILE, "w", newline='') as csvfile:
    fieldnames = list(features[0].keys())
    writer = csv.DictWriter(csvfile, fieldnames=fieldnames)
    writer.writeheader()
    writer.writerows(features)

print("🎉 DAGs, loops, and enriched features saved to combined_features.csv")
