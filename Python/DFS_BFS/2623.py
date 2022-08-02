# 2623 음악프로그램
from collections import deque

N, M = map(int, input().split())    # N : 가수, M : 보조 PD
graph = [[] for _ in range(N + 1)]
degree = [0] * (N + 1)

for i in range(M):
    order = tuple(map(int, input().split()))
    for i in range(1, order[0]):
        graph[order[i]].append(order[i + 1])
        degree[order[i + 1]] += 1

deq = deque()
result = []
for i in range(1, N + 1):
    if degree[i] == 0:
        deq.append(i)

while deq:
    current = deq.popleft()
    result.append(current)
    for i in graph[current]:
        degree[i] -= 1
        if degree[i] == 0:
            deq.append(i)

if len(result) != N:
    print(0)
else:
    for e in result:
        print(e)
