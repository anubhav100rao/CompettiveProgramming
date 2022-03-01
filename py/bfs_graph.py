import queue
import sys
sys.stdin = open('input.txt', 'r')
sys.stdout = open('output.txt', 'w')

from collections import deque

class BFSGraph:
    def __init__(self) -> None:
        pass
    
    def bfsOfGraph(self, V, adj):
        bfs = []
        q = deque()
        q.append(0)
        visited = [False] * V
        visited[0] = True
        while len(q) > 0:
            node = q.pop()
            bfs.append(node)
            for child in adj[node]:
                if not visited[child]:
                    visited[child] = True
                    q.append(child)
        
        return bfs