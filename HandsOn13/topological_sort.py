# This code performs a topological sort on a directed acyclic graph (DAG) using depth-first search (DFS), visiting nodes recursively and storing them based on their finishing time.
# It returns a linear ordering of nodes where each node appears before its dependents, following the defined dependencies.

def dfs_topological_sort(graph, node, visited, stack):
    visited.add(node)
    for neighbor in graph[node]:
        if neighbor not in visited:
            dfs_topological_sort(graph, neighbor, visited, stack)
    stack.append(node)

def topological_sort(graph):
    visited = set()
    stack = []
    for node in graph:
        if node not in visited:
            dfs_topological_sort(graph, node, visited, stack)
    return stack[::-1]

graph = {
    "cricket_pants": ["cricket_shoes", "cricket_belt"],
    "cricket_socks": ["cricket_shoes"],
    "cricket_shirt": ["cricket_cap", "cricket_belt"],
    "cricket_cap": ["cricket_gloves"],
    "cricket_belt": ["cricket_pads"],
    "cricket_shoes": [],
    "cricket_watch": [],
    "cricket_gloves": ["cricket_helmet"],
    "cricket_pads": ["cricket_helmet"],
    "cricket_helmet": []
}

result = topological_sort(graph)
print("Topological Order:", " -> ".join(result))
