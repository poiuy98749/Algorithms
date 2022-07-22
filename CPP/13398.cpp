#include <iostream>
#include <algorithm>
using namespace std;

const int MAX_N = 100000;
int arr[MAX_N];
int dp[MAX_N][2];


int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // dp[n][k] : 'n번째 index에서 끝나는는 연속된 수열의 합의 최댓값'
    // k가 0이면 삭제 X, k가 1이면 삭제 O. 단, 이 때 삭제는 n번째를
    // 삭제했다는 의미가 아니고 n번째를 포함한 '이전 요소들 중' 삭제를
    // 했다는 의미.
    //
    // 삭제를 안한다면 n번째 element는 무조건 선택, 단 이전 요소가
    // 양수라면 더해주고 음수라면 더할 필요가 없다.
    //
    // 삭제를 한다면 n번째 element를 삭제하거나, 이전에 삭제를 한
    // 경우가 있다. 전자는 dp[n - 1][0]이고, 후자의 경우에는
    // dp[n - 1][1] + arr[n]이 된다. 둘 중 최댓값을 써주면 된다.

    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
        cin >> arr[i];

    // DP initialization
    dp[0][0] = arr[0];
    dp[0][1] = max(0, arr[0]);

    // DP
    for (int i = 1; i < N; i++) {
        dp[i][0] = max(arr[i], dp[i - 1][0] + arr[i]);
        dp[i][1] = max(dp[i - 1][0], dp[i - 1][1] + arr[i]);
    }

    // // Print

    // for (int i = 0; i < N; i++) {
    //     cout << dp[i][0] << " ";
    // }
    // cout << "\n";

    // for (int i = 0; i < N; i++) {
    //     cout << dp[i][1] << " ";
    // }
    // cout << "\n";

    if (N == 1) {
        cout << arr[0] << "\n";
        return 0;
    }
    int maximum = dp[0][1];
    if (maximum == 0) maximum = -99999999;
    for (int i = 1; i < N; i++) {
        if (max(dp[i][0], dp[i][1]) > maximum)
            maximum = max(dp[i][0], dp[i][1]);
    }

    cout << maximum << "\n";
    

    return 0;

}