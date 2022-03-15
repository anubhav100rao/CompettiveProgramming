# Kahn's alogrithm
from collections import deque


nodes, edges = map(int, input().split())
graph = [[] for _ in range(nodes+1)]
inDegree = [0] * (nodes+1)
outDegree = [0] * (nodes+1)

for _ in range(0, edges):
    a, b = map(int, input().split())
    graph[a].append(b)

visited_nodes = 0
topo_order = []
q = deque()

for node in range(1, nodes + 1):
    if inDegree[node] == 1:
        visited_nodes += 1
        q.append(node)
        topo_order.append(node)

while q:
    node = q.popleft()
    for child in graph[node]:
        inDegree[child] -= 1
        if inDegree[child] == 0:
            visited_nodes += 1
            q.append(child)
            topo_order.append(child)

if visited_nodes == nodes:
    print(" ".join(map(str, topo_order)))
else:
    print("IMPOSSIBLE")