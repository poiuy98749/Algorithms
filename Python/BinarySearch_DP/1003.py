# 1033 피보나치

N = int(input())
num_list = []

for i in range(N):
    num_list.append(int(input()))

max_num = max(num_list)

# 0부터 max_num까지 dp 배열 생성
dp_list = [(1, 0), (0, 1)]

for i in range(2, max_num + 1):
    zeros_count = dp_list[-2][0] + dp_list[-1][0]
    ones_count = dp_list[-2][1] + dp_list[-1][1]
    dp_list.append((zeros_count, ones_count))

for num in num_list:
    print(dp_list[num][0], dp_list[num][1])