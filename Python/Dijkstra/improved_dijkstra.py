import sys
import heapq

input = sys.stdin.readline
N, M = map(int, input().split())    # N = |V|, M = |E|
start = int(input())
INF = int(1e9)
distance = [INF] * (N + 1)

graph = [[] for _ in range(N + 1)]
for _ in range(M):
    start, end, weight = map(int, input().split())
    graph[start].append((end, weight))

def dijkstra(start):
    q = []
    heapq.heappush(q, (0, start))
    distance[start] = 0

    while q:
        dist, node = heapq.heappop(q)
        if distance[node] < dist:
            continue
        for nextNode in graph[node]:
            # 뽑은 노드의 인접 노드들에 대해서
            cost = distance[node] + next[1]
            if cost < distance[next[0]]:
                distance[next[0]] = cost
                heapq.heappush(q, (cost, next[0]))
        