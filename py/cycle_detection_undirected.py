import sys
sys.stdin = open('input.txt', 'r')
sys.stdout = open('output.txt', 'w')

nodes, edges = map(int, input().split())
adj = [[] for _ in range(nodes)]

for _ in range(edges):
    a, b = map(int, input().split())
    adj[a].append(b)
    adj[b].append(a)

class Graph:
    def __init__(self) -> None:
        pass
    
    
    def detect_cylcle(self, adj, n) -> bool:
        visited = [False] * n
        def dfs(node, parent)-> bool:
            visited[node] = True
            for child in adj[node]:
                if visited[child] and child != parent:
                    return True
                elif not visited[child] and dfs(child, node):
                    return True
            return False
    
        for node in range(n):
            if not visited[node]:
                if dfs(node, None):
                    return True
        return False

print(Graph().detect_cylcle(adj, nodes))