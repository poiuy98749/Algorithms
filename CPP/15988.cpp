#include <iostream>
using namespace std;

const int MAX_LENGTH = 1000000;
const int MOD = 1000000009;
long long int dp[MAX_LENGTH + 1];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long T, num;
    cin >> T;

    // DP initialization
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;

    for (int i = 3; i < MAX_LENGTH; i++) {
        dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 3]) % MOD;
    }

    for (int i = 0; i < T; i++) {
        cin >> num;
        cout << dp[num] % MOD << "\n";
    }

    return 0;
}