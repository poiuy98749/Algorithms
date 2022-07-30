# 2565 전깃줄

N = int(input())
AB = []
B = []

for i in range(N):
    x, y = map(int, input().split())
    AB.append((x, y))

AB.sort(key=lambda x:x[0])

for ab in AB:
    B.append(ab[1])

# B에서 가장 긴 증가하는 부분 수열의 길이를 구해준다.
dp = [1] * len(B)

for i in range(1, N):
    for j in range(i):
        if B[i] > B[j]:
            dp[i] = max(dp[i], dp[j] + 1)

print(len(B) - max(dp))