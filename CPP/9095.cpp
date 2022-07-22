#include <iostream>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    int num;
    int* dp = new int[11];
    cin >> T;

    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;

    for (int i = 0; i < T; i++) {
        cin >> num;
        if (num <= 2) {
            cout << dp[num] << "\n";
            continue;
        }
        for (int i = 3; i <= num; i++)
            dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
        
        cout << dp[num] << "\n";
    }
    return 0;
}