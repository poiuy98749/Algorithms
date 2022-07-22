#include <iostream>
using namespace std;

const int MOD = 1000000000;
const int MAX_N = 200;
const int MAX_K = 200;
int dp[MAX_K + 1][MAX_N + 1];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // Dynamic programming 조건을 만족시킨다.
    // dp[n][k] : 'k개를 더해서 n을 만드는 경우의 수'
    // = 'k - 1개를 더해서 n을 만드는 경우의 수' +
    //   'k - 1개를 더해서 n - 1을 만드는 경우의 수' +
    //   ...
    //   'k - 1개를 더해서 0을 만드는 경우의 수'
    //
    // -> dp[k][n] = dp[n][k - 1] + dp[n - 1][k] + ...
    //               dp[1][k - 1] + dp[0][k - 1];

    int N, K;
    cin >> N >> K;

    // DP initialization
    for (int i = 0; i <= K; i++)
        dp[0][i] = 1;
    
    for (int i = 1; i <= N; i++)
        dp[i][0] = 0;
    
    // DP
    for (int column = 1; column <= K; column++) {
        for (int row = 1; row <= N; row++) {
            dp[row][column] = (dp[row - 1][column] + dp[row][column - 1]) % MOD;
        }
    }

    cout << dp[N][K] % MOD << "\n";
    return 0;
}