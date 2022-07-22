#include <iostream>
using namespace std;

const int MAX_N = 100000;
const int MOD = 9901;
int dp[MAX_N + 1][3];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // Dynamic programming 조건을 만족시킨다. 
    // dp[n][k] : n번째 row에서 사자를 넣지 않거나, 1번째 column에만 넣거나, 2번째 column에만
    // 넣는 경우의 수 (k가 각각 0, 1, 2)
    // dp[n][0] : n - 1번째 row에 사자를 어떻게 넣든 상관이 없음. 즉, 3가지를 다 더하면 됨.
    // dp[n][1] : n - 1번째 row에서 1번째 column에만 안 넣으면 됨.
    // dp[n][1] : n - 1번째 row에서 2번째 column에만 안 넣으면 됨.


    int N;
    cin >> N;

    // DP initialization
    dp[1][0] = 1; dp[1][1] = 1; dp[1][2] = 1;

    // DP
    for (int i = 2; i <= N; i++) {
        dp[i][0] = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2]) % MOD;
        dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]) % MOD;
        dp[i][2] = (dp[i - 1][0] + dp[i - 1][1]) % MOD;
    }

    // Print
    cout << (dp[N][0] + dp[N][1] + dp[N][2]) % MOD << "\n";
    return 0;
}