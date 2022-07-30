# 2805 나무 자르기

def getTotalWoods(woods, length):
    # length의 높이로 잘랐을 때 얻을 수 있는 나무의 총 길이를 return한다.
    total = 0
    for wood in woods:
        if wood > length:   # 나무의 길이가 높이보다 커야 자를 수 있다.
            total += (wood - length)
    
    return total


N, M = map(int, input().split()) # N : 나무의 수, M : 나무의 목표 길이
woods = list(map(int, input().split()))

search_limit = max(woods)   # 나무의 최대 길이까지만 탐색하면 된다.
left = 1; right = search_limit

while left <= right:
    current = (left + right) // 2
    if getTotalWoods(woods, current) >= M:
        left = current + 1
    else:
        right = current - 1

print(right)
