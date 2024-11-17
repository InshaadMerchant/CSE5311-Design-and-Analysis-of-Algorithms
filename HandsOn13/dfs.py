# This DFS code recursively traverses a graph from a starting node to search for a specified target node, stopping early if the target is found. 
# It keeps track of visited nodes to prevent revisits and cycles.

def dfs(graph, node, target, visited):
    if node == target:
        print(f"Found target node: {node}")
        return True
    
    visited.add(node)
    for neighbor in graph[node]:
        if neighbor not in visited:
            if dfs(graph, neighbor, target, visited):
                return True
    return False

graph = {
    "cricket_pants": ["cricket_shirt", "cricket_shoes"],
    "cricket_socks": ["cricket_shoes"],
    "cricket_shirt": ["cricket_cap", "cricket_belt"],
    "cricket_cap": ["cricket_gloves"],
    "cricket_belt": ["cricket_pads"],
    "cricket_shoes": [],
    "cricket_gloves": ["cricket_helmet"],
    "cricket_pads": ["cricket_helmet"],
    "cricket_helmet": []
}

visited = set()
target_node = "cricket_helmet"
print("Target node: Cricket Helmet")
print("Starting node: Cricket Pants")
found = dfs(graph, "cricket_pants", target_node, visited)

if not found:
    print("Target node not found in the graph.")
