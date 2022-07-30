# 1477 휴게소 세우기
# 거리를 기준으로 이분 탐색을 해주면 된다.

# N : 현재 휴게소의 개수
# M : 더 지으려고 하는 휴게소의 개수
# L : 도로의 길이
N, M, L = map(int, input().split())
locations = list(map(int, input().split()))
locations.sort()
locations = [0] + locations + [L]

left, right = 1, L - 1
result = 0

while left <= right:
    count = 0
    current = (left + right) // 2
    for i in range(1, len(locations)):
        if locations[i] - locations[i - 1] > current:
            count += (locations[i] - locations[i - 1] - 1) // current
    
    if count > M:
        left = current + 1
    else:
        right = current - 1
        result = current
    
print(result)