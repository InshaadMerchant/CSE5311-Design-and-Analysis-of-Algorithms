def bellman_ford(graph, start):
    distances = {node: float('inf') for node in graph}
    distances[start] = 0
    predecessors = {node: None for node in graph}

    for _ in range(len(graph) - 1):
        for node in graph:
            for neighbor, weight in graph[node].items():
                if distances[node] + weight < distances[neighbor]:
                    distances[neighbor] = distances[node] + weight
                    predecessors[neighbor] = node
    for node in graph:
        for neighbor, weight in graph[node].items():
            if distances[node] + weight < distances[neighbor]:
                raise ValueError("Graph contains a negative-weight cycle")
    
    return distances, predecessors

if __name__ == "__main__":
    # figure 24.4
    graph = {
        's': {'t': 6, 'y': 7},
        't': {'x': 5, 'y': 8, 'z': -4},
        'x': {'t': -2},
        'y': {'z': 9, 'x': -3},
        'z': {'s': 2, 'x': 7}
    }

    distances, predecessors = bellman_ford(graph, 's')
    print("Distances:", distances)
    print("Predecessors:", predecessors)