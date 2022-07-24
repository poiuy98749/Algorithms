# 2579 계단 오르기
# dp_k[i] : i번째 계단을 연속 k번째로 밟았을 때 해당 계단까지의
# 점수의 최댓값

# dp_1[i] = max(dp_1[i - 2], dp_2[i - 2]) + stairs[i]
# dp_2[i] = dp_1[i - 1] + stairs[i]

stairs = []
N = int(input())
for i in range(N):
    stairs.append(int(input()))

dp_1 = [0, stairs[0]]
dp_2 = [0, -1]  # 0번째 계단은 연속해서 2번째로 밟는 것이 불가능

for i in range(N - 1):
    dp_1.append(max(dp_1[-2], dp_2[-2]) + stairs[i + 1])
    dp_2.append(dp_1[-2] + stairs[i + 1])

del dp_2[-2]
# print(dp_1)
# print(dp_2)
print(max(max(dp_1), max(dp_2)))


