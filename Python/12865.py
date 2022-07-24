# 12865 평범한 배낭

# dp[i][j] : i번째 item까지 확인했을 때 무게가 j 남아있는 배낭에 넣을 수
# 있는 물건들의 최대 가치
# dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - W[i]] + V[i])

# N : 물품의 수
# K : 최대 무게
# 물건 : (W, V) - W : 무게, V : 가치
N, K = map(int, input().split())
items = [(0, 0)]
for i in range(N):
    W, V = map(int, input().split())
    items.append((W, V))

dp = []
for _ in range(N + 1):
    dp.append([0] * (K + 1))

for i in range(1, N + 1):
    for j in range(1, K + 1):
        if items[i][0] <= j:
            # i번째 물건을 넣을 수 있는 경우
            dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - items[i][0]] + items[i][1])
        else:
            dp[i][j] = dp[i - 1][j]

print(dp[N][K])