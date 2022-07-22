#include <iostream>
using namespace std;

const int MAX_N = 1000;
int arr[MAX_N];
int dp[MAX_N];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // Dynamic programming 조건을 만족시킨다.
    // dp[i] : 'i번째 element를 부분 수열의 마지막 요소로 선택했을 때,
    // 부분 수열의 합의 최댓값'
    // dp[i] : max(dp[x1], dp[x2], ...), 단 x1 < i && x2 < i && ...
    // 즉, i번째 element보다 작은 값을 부분 수열의 마지막 요소로 갖는
    // 부분 수열의 합의 최댓값 + i번째 element를 해주면 된다.
    // 이는 증가하는 부분수열이라는 제약 조건 때문이다.

    int T;
    cin >> T;

    for (int i = 0; i < T; i++)
        cin >> arr[i];
    
    // DP initialize
    dp[0] = arr[0];

    // DP
    for (int i = 1; i < T; i++) {
        int max = 0;
        for (int j = 0; j < i; j++) {
            if (arr[j] < arr[i] && dp[j] > max) {
                max = dp[j];
            }
        }
        dp[i] = max + arr[i];
    }

    int max = dp[0];
    for (int i = 0; i < T; i++) {
        if (dp[i] > max) max = dp[i];
    }
    cout << max << "\n";
    return 0;
}