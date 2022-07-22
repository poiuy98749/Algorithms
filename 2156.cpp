#include <iostream>
#include <algorithm>
using namespace std;

const int MAX_N = 10000;
int arr[MAX_N];
int dp[3][MAX_N];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // Dynamic programming 조건을 만족시킨다.
    // 특정 포도주를 선택하지 않거나, 첫 번째로 선택하거나, 연속해서
    // 두 번째로 선택할 수 있다. 이 3가지를 dp 배열의 row로 구성한다.
    //
    // dp[k][i] : 'i번째 포도주를 k번째로 선택했을 때 최대 양' (k = 0이면 선택 X)
    //
    // dp[0][i] = max(dp[0][i - 1], dp[1][i - 1], dp[2][i - 1])
    // dp[1][i] = dp[0][i - 1] + arr[i] (직전에 안 마셨어야 1번째가 됨)
    // dp[2][i] = dp[1][i - 1] + arr[i] (직전에 마셨어야 2번째가 됨)

    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
        cin >> arr[i];
    
    // dp initialize
    dp[0][0] = 0; dp[1][0] = arr[0]; dp[2][0] = 0;

    // dp
    for (int i = 1; i < N; i++) {
        dp[0][i] = max({dp[0][i - 1], dp[1][i - 1], dp[2][i - 1]});
        dp[1][i] = dp[0][i - 1] + arr[i];
        dp[2][i] = dp[1][i - 1] + arr[i];
    }

    cout << max({dp[0][N - 1], dp[1][N - 1], dp[2][N - 1]}) << "\n";
    
    return 0;
}