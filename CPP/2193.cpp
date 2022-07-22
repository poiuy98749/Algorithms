#include <iostream>
using namespace std;

const int MAX_NUM = 90;
long long dp[MAX_NUM + 1][2];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // Dynamic programming의 조건을 만족시킨다.
    // dp[n][k] (k는 0 또는 1)을 '길이가 n인 이친수 중 끝자리가
    // k인 이친수의 개수'로 정의하면 된다.
    // dp[n][0] = dp[n - 1][0] + dp[n - 1][1]
    // dp[n][1] = dp[n - 1][0]
    
    long long num;
    cin >> num;

    dp[1][0] = 0; dp[1][1] = 1;

    for (int i = 2; i <= num; i++) {
        dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
        dp[i][1] = dp[i - 1][0];
    }

    // 전부 더해서 합을 출력
    cout << dp[num][0] + dp[num][1] << "\n";
    return 0;
}