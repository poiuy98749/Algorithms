# 1260 DFS와 BFS

from collections import deque

N, M, V = map(int, input().split())
visited = [False] * (N + 1)
graph = []

for _ in range(N + 1):
    graph.append([])

for _ in range(M):
    start, end = map(int, input().split())
    graph[start].append(end)
    graph[end].append(start)

for i in range(len(graph)):
    graph[i].sort()


def dfs(start):
    print(start, end=' ')
    visited[start] = True
    for i in graph[start]:
        if not visited[i]:
            dfs(i)
            visited[i] = True

def bfs(start):
    deq = deque([start])
    visited[start] = True
    while deq:
        current = deq.popleft()
        print(current, end=' ')
        for i in graph[current]:
            if not visited[i]:
                deq.append(i)
                visited[i] = True

dfs(V)
visited = [False] * (N + 1)
print()
bfs(V)

