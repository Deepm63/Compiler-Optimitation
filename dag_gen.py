import os
import random
import pickle
import networkx as nx

SAVE_DIR = "dag_dataset"
os.makedirs(SAVE_DIR, exist_ok=True)

NUM_DAGS = 100
MIN_NODES = 6
MAX_NODES = 10
DEPENDENCY_TYPES = ['true', 'anti', 'output']

def generate_dag(dag_id, num_nodes):
    dag = nx.DiGraph()
    for i in range(num_nodes):
        dag.add_node(i, label=f"S{i+1}")

    edge_count = 0
    max_edges = 2 * num_nodes
    while edge_count < max_edges:
        u = random.randint(0, num_nodes - 2)
        v = random.randint(u + 1, num_nodes - 1)
        if not dag.has_edge(u, v):
            dep_type = random.choice(DEPENDENCY_TYPES)
            dag.add_edge(u, v, type=dep_type)
            edge_count += 1

    assert nx.is_directed_acyclic_graph(dag)
    return dag

for dag_id in range(NUM_DAGS):
    n = random.randint(MIN_NODES, MAX_NODES)
    dag = generate_dag(dag_id, n)
    with open(f"{SAVE_DIR}/loop_dag_{dag_id}.pkl", "wb") as f:
        pickle.dump(dag, f)

print("✅ Dependency-correct DAGs generated.")
