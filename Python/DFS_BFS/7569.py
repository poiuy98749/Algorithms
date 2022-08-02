# 7569 토마토
from collections import deque

dh = [0, 0, 0, 0, 1, -1]
dy = [0, 0, 1, -1, 0, 0]
dx = [1, -1, 0, 0, 0, 0]

# List structure를 H -> N -> M으로 하자.
X, Y, H = map(int, input().split())
graph = []; deq = deque()

for _ in range(H):
    graph.append([])

for h in range(H):
    for n in range(Y):
        graph[h].append(list(map(int, input().split())))

# 처음에 익어있는 토마토의 위치를 큐에 추가해 준다.
for h in range(H):
    for y in range(Y):
        for x in range(X):
            if graph[h][y][x] == 1:
                deq.append((h, y, x))

# BFS
def bfs(H, Y, X):
    while deq:
        h_, y_, x_ = deq.popleft()
        for i in range(6):
            new_h = h_ + dh[i]
            new_y = y_ + dy[i]
            new_x = x_ + dx[i]
            if new_h < 0 or new_h >= H or new_y < 0 or new_y >= Y or new_x < 0 or new_x >= X:
                continue
            if graph[new_h][new_y][new_x] == 0:
                # 아직 안 익은 토마토이므로 1을 더해준다.
                # 1을 더한 것은 중심 토마토를 기준으로 하루만큼 더 지난 것이기 때문이다.
                graph[new_h][new_y][new_x] = graph[h_][y_][x_] + 1
                deq.append((new_h, new_y, new_x))

bfs(H, Y, X)

# 안익은 토마토가 존재하는지 확인
inValid = False
for h in range(H):
    for y in range(Y):
        for x in range(X):
            if graph[h][y][x] == 0:
                inValid = True
                break

if inValid:
    print(-1)

else:
    # 가장 익는데 오래 걸린 토마토를 찾으면 된다.
    tempMax = 0
    for h in range(H):
        for y in range(Y):
            for x in range(X):
                tempMax = max(tempMax, graph[h][y][x])
    
    print(tempMax - 1)
