#2667 단지번호붙이기
from collections import deque

dx = [0, 0, 1, -1]
dy = [1, -1, 0, 0]

graph = []
N = int(input())    # 지도의 크기

for _ in range(N):
    graph.append(list(map(int, input())))

def bfs(graph, x, y):
    N = len(graph)  # 가로, 세로 크기
    deq = deque()
    deq.append((x, y))
    graph[x][y] = 0
    count = 1

    while deq:
        current_x, current_y = deq.popleft()
        for i in range(4):
            new_x = current_x + dx[i]
            new_y = current_y + dy[i]
            if new_x < 0 or new_x >= N or new_y < 0 or new_y >= N:
                continue
            if graph[new_x][new_y] == 1:
                # 주변 vertex가 1이면 (존재하면) 해당 vertex를 0으로 바꾸어서 visited로 표시해 준다.
                graph[new_x][new_y] = 0
                deq.append((new_x, new_y))
                count += 1
    return count

counts = []
for i in range(N):
    for j in range(N):
        if graph[i][j] == 1:
            # 1인 vertex가 있으면 bfs를 해서 모두 0으로 바꾸어 주고 connected components의
            # 개수를 counts 배열에 추가해 준다.
            counts.append(bfs(graph, i, j))

counts.sort()
print(len(counts))
for i in range(len(counts)):
    print(counts[i])
