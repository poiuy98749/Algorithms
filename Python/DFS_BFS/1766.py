# 1766 문제집
import heapq

N, M = map(int, input().split())
result = []
graph = [[] for _ in range(N + 1)]
degree = [0] * (N + 1)
priorityQueue = []


for i in range(M):
    start, end = map(int, input().split())
    graph[start].append(end)
    degree[end] += 1

for i in range(1, N + 1):
    if degree[i] == 0:
        heapq.heappush(priorityQueue, i)

while priorityQueue:
    current = heapq.heappop(priorityQueue)
    result.append(current)

    for i in graph[current]:
        # 인접한 vertex에 대해서
        degree[i] -= 1
        if degree[i] == 0:
            heapq.heappush(priorityQueue, i)
    

for e in result:
    print(e, end=' ')