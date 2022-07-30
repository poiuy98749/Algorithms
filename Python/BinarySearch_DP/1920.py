# 1920 수 찾기
# List에서의 in operator는 time complexity가 O(N)이므로
# 시간 초과, set에서는 평균적으로 O(1)로 가능
# Set은 내부적으로 hashtable을 사용하므로 큰 차이가 있음

A = []
B = []

N = int(input())
A = list(map(int, input().split()))
M = int(input())
B = list(map(int, input().split()))

A_set = set(A)

for num in B:
    if num in A_set:
        print(1)
    else:
        print(0)
