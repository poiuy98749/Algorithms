#include <iostream>
using namespace std;

const int MAX_N = 100000;
const int mod = 1e9 + 9;
long long dp[MAX_N + 1][3];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    int num;
    cin >> T;
    
    dp[0][0] = dp[0][1] = dp[0][2] = 0;
    dp[1][0] = 1; dp[1][1] = dp[1][2] = 0;
    dp[2][0] = dp[2][2] = 0; dp[2][1] = 1;
    dp[3][0] = dp[3][1] = dp[3][2] = 1;


    for (int i = 0; i < T; i++) {
        cin >> num;
        if (num >= 4) {
            for (int i = 4; i <= num; i++) {
                dp[i][0] = (dp[i - 1][1] + dp[i - 1][2]) % mod;
                dp[i][1] = (dp[i - 2][0] + dp[i - 2][2]) % mod;
                dp[i][2] = (dp[i - 3][0] + dp[i - 3][1]) % mod;
            }
        }
        cout << (dp[num][0] + dp[num][1] + dp[num][2]) % mod << "\n";
    }

    return 0;
}