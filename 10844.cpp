#include <iostream>
using namespace std;

const int MAX_NUM = 100;
const int MOD = 1000000000;
int dp[MAX_NUM + 1][10];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // Dynamic programming 조건을 만족시킨다.
    // dp[n][k] = '길이가 n이면서 끝 자리가 k인 계단수' 로 정의.
    // 길이가 n이고 k로 끝나는 계단수는 길이가 (n - 1)이고 (k - 1)로
    // 끝나는 계단수의 개수 + 길이가 (n - 1)이고 (k + 1)로 끝나는
    // 계단수의 개수. 단, k가 0이거나 9이면 따로 처리해줘야 함.
    // 즉, dp[n][k] = dp[n - 1][k - 1] + dp[n - 1][k + 1]
    // 단, k가 0이거나 9이면 한 쪽만 더해줘야 함.

    int num;
    cin >> num;

    // 초기조건
    dp[1][0] = 0;
    for (int i = 1; i <= 9; i++)
        dp[1][i] = 1;
    
    for (int i = 2; i <= num; i++) {
        // 끝 자리가 0이거나 9인 경우는 따로 처리
        dp[i][0] = dp[i - 1][1];
        dp[i][9] = dp[i - 1][8];

        for (int j = 1; j <= 8; j++)
            dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % MOD;
    }

    // 전부 더해서 합을 출력
    int sum = 0;
    for (int i = 0; i <= 9; i++) {
        sum = (sum + dp[num][i]) % MOD;
    }

    cout << sum % MOD << "\n";

    
    return 0;
}