# 1654 랜선 자르기
# 길이를 1부터 brute-force로 탐색하면 시간 초과

def count(lans, length):
    # 랜선들의 리스트인 lans를 length의 길이로 잘랐을 때 총 막대의 개수를 구한다.
    count = 0
    for lan in lans:
        count += lan // length
    
    return count


K, N = map(int, input().split()) # K : 가지고 있는 개수, N : 목표 개수
K_list = []
for i in range(K):
    K_list.append(int(input()))

search_limit = max(K_list)  # 가장 긴 막대의 길이가 binary search의 끝이 된다.
left = 1
current = search_limit // 2
right = search_limit

while left <= right:
    current = (left + right) // 2
    current_count = count(K_list, current)

    if current_count >= N:
        left = current + 1
    else:
        right = current - 1

print(right)
