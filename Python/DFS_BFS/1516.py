# 1516 게임 개발
from collections import deque

N = int(input())    # 건물의 종류
graph = [[] for _ in range(N + 1)]
degree = [0] * (N + 1)
weights = [0] * (N + 1)
deq = deque()

for i in range(1, N + 1):
    line = list(map(int, input().split()))
    weights[i] = line[0]

    # Edge 연결
    # print(line)
    for j in range(1, len(line) - 1):
        # print(f"graph({j}).append({i})")
        graph[line[j]].append(i)
        degree[i] += 1


result = [0] * (N + 1)
for i in range(1, N + 1):
    if degree[i] == 0:
        deq.append(i)

while deq:
    current = deq.popleft()
    result[current] += weights[current]
    for v in graph[current]:
        degree[v] -= 1
        result[v] = max(result[v], result[current])
        if degree[v] == 0:
            deq.append(v)

for i in range(1, N + 1):
    print(result[i])

# print(graph)