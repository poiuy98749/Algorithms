#include <iostream>
#include <algorithm>
using namespace std;

const int MAX_N = 500;
int arr[MAX_N][MAX_N];
int dp[MAX_N][MAX_N];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // Dynamic programming 조건을 만족시킨다.
    // dp[i][j] : '위에서 i번째 row, 왼쪽에서 j번째 column의 요소를 선택했을
    // 때 해당 요소까지 합의 최댓값' 으로 정의한다.
    // j가 0이면 dp[i][j] = dp[i - 1][j] + arr[i][j]
    // j가 end(끝)이면 dp[i][j] = dp[i - 1][end - 1] + arr[i][j]
    // 둘 다 아니라면 dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + arr[i][j]
    //
    int H;
    cin >> H;

    // Fill arr
    for (int i = 0; i < H; i++) {
        for (int j = 0; j <= i; j++)
            cin >> arr[i][j];
    }

    // DP initialize
    dp[0][0] = arr[0][0];

    // DP
    for (int i = 1; i < H; i++) {
        dp[i][0] = dp[i - 1][0] + arr[i][0];
        dp[i][i] = dp[i - 1][i - 1] + arr[i][i];
        for (int j = 1; j < i; j++) {
            dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + arr[i][j];
        }
    }

    // Find maximum
    int maximum = dp[H - 1][0];
    for (int i = 1; i < H; i++) {
        if (dp[H - 1][i] > maximum) {
            maximum = dp[H - 1][i];
        }
    }
    
    cout << maximum << "\n";
    return 0;
}