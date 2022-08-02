# 2252 줄 세우기
# Topological sort는 각 작업들 간의 순서가 정해져 있을 때
# 사용하면 편하다.
from collections import deque


N, M = map(int, input().split())    # N명 학생, M번 비교
graph = [[] for _ in range(N + 1)]
degree = [0] * (N + 1)
deq = deque()

for i in range(M):
    # A -> B 순서가 정해진다면 A, B는 각각 degree가 0, 1이 된다.
    first, second = map(int, input().split())
    graph[first].append(second)
    degree[second] += 1

# N명의 사람들의 degree를 확인해서 degree가 0인 사람들
# (가장 앞에 올 수 있는 사람들)을 먼저 queue에 넣어준다.
for i in range(1, N + 1):
    if degree[i] == 0:
        deq.append(i)

result = []
while deq:
    temp = deq.popleft()
    result.append(temp)
    for neighbor in graph[temp]:
        # neighbor로 들어가는 edge의 수가 하나 줄어들게 한다.
        degree[neighbor] -= 1
        if degree[neighbor] == 0:
            # degree가 0이라면 이제 순서 제약이 없어진 것이므로
            # queue에 넣어주면 된다.
            deq.append(neighbor)

for e in result:
    print(e, end=' ')