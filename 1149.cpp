#include <iostream>
#include <algorithm>
using namespace std;

const int MAX_N = 1001;
const int MAX_COLOR = 3;
int arr[MAX_N][MAX_COLOR];
int dp[MAX_N][MAX_COLOR];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // Dynamic programming 조건을 만족시킨다.
    // dp[n][k] : n번째 집을 k색으로 칠한다고 가정했을 때
    // 최소 비용.
    //
    // dp[n][0] = min(dp[n - 1][1], dp[n - 2][2]) + arr[n][0];
    // dp[n][1] = min(dp[n - 1][0], dp[n - 2][2]) + arr[n][1];
    // dp[n][2] = min(dp[n - 1][0], dp[n - 2][1]) + arr[n][2];
    
    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < MAX_COLOR; j++) {
            cin >> arr[i][j];
        }
    }

    // DP initialization
    dp[1][0] = arr[1][0];
    dp[1][1] = arr[1][1];
    dp[1][2] = arr[1][2];

    // DP
    for (int i = 2; i <= N; i++) {
        dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + arr[i][0];
        dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + arr[i][1];
        dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + arr[i][2];
    }

    // Print
    cout << min({dp[N][0], dp[N][1], dp[N][2]}) << "\n";

    return 0;
}