import heapq

def dijkstra(graph, start):
    distances = {node: float('inf') for node in graph}
    distances[start] = 0
    pq = [(0, start)]
    predecessors = {node: None for node in graph}

    while pq:
        current_distance, current_node = heapq.heappop(pq)
        if current_distance > distances[current_node]:
            continue

        for neighbor, weight in graph[current_node].items():
            distance = current_distance + weight
            if distance < distances[neighbor]:
                distances[neighbor] = distance
                predecessors[neighbor] = current_node
                heapq.heappush(pq, (distance, neighbor))
    
    return distances, predecessors

# figure 24.6
graph = {
    's': {'t': 10, 'y': 5},
    't': {'x': 1, 'y': 2},
    'x': {},
    'y': {'z': 2, 't': 3},
    'z': {'x': 6, 's': 7}
}

distances, predecessors = dijkstra(graph, 's')
print("Distances:", distances)
print("Predecessors:", predecessors)