# 1149 RGB거리

# dp[i][j] : i번째 집을 j번째 색으로 칠하는 비용의 최솟값 (i번째 집까지만)
# dp[i][j] = min(dp[i - 1][x], dp[i - 1][y]) + RGB_costs[i] (x != j)
N = int(input())
RGB_costs = []
for i in range(N):
    RGB_costs.append(tuple(map(int, input().split())))

dp_R = [RGB_costs[0][0]]
dp_G = [RGB_costs[0][1]]
dp_B = [RGB_costs[0][2]]

for i in range(1, N):
    dp_R.append(min(dp_G[i - 1], dp_B[i - 1]) + RGB_costs[i][0])
    dp_G.append(min(dp_R[i - 1], dp_B[i - 1]) + RGB_costs[i][1])
    dp_B.append(min(dp_R[i - 1], dp_G[i - 1]) + RGB_costs[i][2])

print(min(dp_R[N - 1], dp_G[N - 1], dp_B[N - 1]))
# print(dp_R)
# print(dp_G)
# print(dp_B)

