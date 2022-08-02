# 1012 유기농 배추
from collections import deque

dx = [1, -1, 0, 0]; dy = [0, 0, 1, -1]

def bfs(graph, x, y):
    H = len(graph)
    W = len(graph[0])

    deq = deque()
    deq.append((x, y))
    graph[y][x] = 0

    while deq:
        current_x, current_y = deq.popleft()
        for i in range(4):
            new_x = current_x + dx[i]
            new_y = current_y + dy[i]
            if new_x < 0 or new_x >= W or new_y < 0 or new_y >= H:
                continue
            if graph[new_y][new_x] == 1:
                # 주변이 1이면 0으로 바꾸고 (visited 수정) deque에 삽입
                graph[new_y][new_x] = 0
                deq.append((new_x, new_y))


def execute():
    M, N, K = map(int, input().split()) # M이 가로, N이 세로
    graph = []
    for _ in range(N):
        graph.append([0] * M)

    for _ in range(K):
        x, y = map(int, input().split())
        graph[y][x] = 1
    
    count = 0
    for i in range(N):
        for j in range(M):
            if graph[i][j] == 1:
                count += 1
                bfs(graph, j, i)
    
    print(count)
    

T = int(input())    # TC 개수

for _ in range(T):
    execute()
