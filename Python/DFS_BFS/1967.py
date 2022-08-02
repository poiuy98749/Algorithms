# 1967 트리의 지름
import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**6)

N = int(input())    # |V|
graph = [[] for _ in range(N + 1)]
distances = [-1] * (N + 1)  # 1번 vertex부터의 거리
distances[1] = 0


for _ in range(N - 1):
    start, end, weight = map(int, input().split())
    graph[start].append((end, weight))
    graph[end].append((start, weight))  # Undirected graph이기 때문


def dfs(graph, current, weight):
    for end, w in graph[current]:
        if distances[end] == -1:
            # 해당 노드까지의 거리가 아직 갱신이 안 되었다면 업데이트
            distances[end] = weight + w
            dfs(graph, end, weight + w)

dfs(graph, 1, 0)
# 이제 distances list에 vertex 1로부터의 거리가 모두 저장되어 있다.

new_start = distances.index(max(distances))

# distances 배열은 초기화
distances = [-1] * (N + 1)  # new_start번 vertex부터의 거리
distances[new_start] = 0

dfs(graph, new_start, 0)
print(max(distances))