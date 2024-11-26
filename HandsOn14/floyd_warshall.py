def floyd_warshall(graph):
    nodes = list(graph.keys())
    n = len(nodes)
    dist = {u: {v: float('inf') for v in nodes} for u in nodes}
    for u in graph:
        for v in graph[u]:
            dist[u][v] = graph[u][v]
        dist[u][u] = 0  # dist to self = 0
    for k in nodes:
        for i in nodes:
            for j in nodes:
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])
    return dist

if __name__ == "__main__":
    # figure 25.1, 25.4
    graph = {
        '1': {'2': 3, '5': -4},
        '2': {'3': 8, '5': 7},
        '3': {'4': 1},
        '4': {'2': -5},
        '5': {'3': 2, '4': 6}
    }
    distances = floyd_warshall(graph)
    print("Shortest distances:")
    for u in distances:
        print(u, distances[u])