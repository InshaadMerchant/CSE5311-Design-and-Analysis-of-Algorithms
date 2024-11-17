# This program implements Kruskal's algorithm using union-find to construct the Minimum Spanning Tree (MST) of a graph, adding edges step by step without forming cycles.
# It outputs the MST with a detailed step-by-step log and the total weight of the tree.

class DisjointSet:
    def __init__(self, n):
        self.parent = list(range(n))
        self.rank = [0] * n

    def find(self, u):
        if self.parent[u] != u:
            self.parent[u] = self.find(self.parent[u])
        return self.parent[u]

    def union(self, u, v):
        root_u = self.find(u)
        root_v = self.find(v)
        if root_u != root_v:
            if self.rank[root_u] > self.rank[root_v]:
                self.parent[root_v] = root_u
            elif self.rank[root_u] < self.rank[root_v]:
                self.parent[root_u] = root_v
            else:
                self.parent[root_v] = root_u
                self.rank[root_u] += 1

def kruskal(n, edges):
    edges.sort(key=lambda x: x[2])
    ds = DisjointSet(n)
    mst = []
    mst_weight = 0
    steps = []

    for u, v, weight in edges:
        if ds.find(u) != ds.find(v):
            ds.union(u, v)
            mst.append((u, v, weight))
            mst_weight += weight
            mst_step = [(u, v, weight)]
            steps.append(mst_step)

    return mst, mst_weight, steps

# a = 0, b = 1, c = 2, d = 3, e = 4, f = 5, g = 6, h = 7, i = 8
# (source, dest, weight)
edges = [
    (0, 1, 4),   # a-b
    (0, 7, 8),   # a-h
    (1, 2, 8),   # b-c
    (1, 7, 11),  # b-h
    (2, 3, 7),   # c-d
    (2, 8, 2),   # c-i
    (2, 5, 4),   # c-f
    (3, 4, 9),   # d-e
    (3, 5, 14),  # d-f
    (4, 5, 10),  # e-f
    (5, 6, 2),   # f-g
    (6, 7, 1),   # g-h
    (6, 8, 6),   # g-i
    (7, 8, 7)    # h-i
]

num_vertices = 9
mst, mst_weight, steps = kruskal(num_vertices, edges)
vertex_map = {0: 'a', 1: 'b', 2: 'c', 3: 'd', 4: 'e', 5: 'f', 6: 'g', 7: 'h', 8: 'i'}
mst_readable = [(vertex_map[u], vertex_map[v], w) for u, v, w in mst]

print("Step-by-step MST construction:")
for i, step in enumerate(steps):
    step_readable = [(vertex_map[u], vertex_map[v], w) for u, v, w in step]
    print(f"Step {i + 1}: Added edge {step_readable}")

print("\nFinal MST:", mst_readable)
print("Total weight of the MST:", mst_weight)