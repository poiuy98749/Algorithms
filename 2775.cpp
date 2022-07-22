#include <iostream>
using namespace std;

int main(void) {
    int num_of_tc;
    int dp[15][15];
    int k, n;
    cin >> num_of_tc;

    for (int i = 0; i < num_of_tc; i++) {
        cin >> k >> n;

        // Initialize the first floor
        for (int i = 1; i <= n; i++)   // Room number : 1, 2, 3, ...
        dp[0][i] = i;

        // Fill the multidimensional array
        for (int i = 1; i < k + 1; i++) {
            for (int j = 1; j <= n; j++) {
                int sum = 0;
                for (int k = 1; k <= j; k++) {
                    sum += dp[i - 1][k];
                }
                dp[i][j] = sum;
            }
        }
        cout << dp[k][n] << endl;
    }    
    return 0;
}