#include <iostream>
#include <algorithm>
using namespace std;

const int MAX_N = 100000;
int arr[2][MAX_N];
int dp[3][MAX_N];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // Dynamic programming 조건을 만족시킨다.
    // # 특정 column의 스티커는 0행 선택 / 1행 선택 / 선택 X 가 가능하다.
    // dp[choice][i]를 'i번째 column에서 choice(0, 1, 2)를 택했을 때 가능한
    // i번째 column까지 최대의 점수' 로 정의한다.
    // 만약 choice가 0이면 직전 column에서 1이나 2를 택한 경우 중 최댓값
    // 만약 choice가 1이면 직전 column에서 0이나 2를 택한 경우 중 최댓값
    // 만약 choice가 2이면 직전 column에서의 최댓값
    // 이렇게 다음 column을 채워주면 된다.
    // 아예 안 선택할 수도 있다는 것이 중요하고, 이를 2를 택하는 것으로 한다.

    int T, N;
    cin >> T;
    
    for (int i = 0; i < T; i++) {
        // 일단 배열을 모두 채운다.
        cin >> N;
        for (int j = 0; j < N; j++)
            cin >> arr[0][j];
        for (int j = 0; j < N; j++)
            cin >> arr[1][j];
        
        // DP initialize
        dp[0][0] = arr[0][0];
        dp[1][0] = arr[1][0];
        dp[2][0] = 0;

        // DP
        for (int j = 1; j < N; j++) {
            dp[0][j] = max(dp[1][j - 1], dp[2][j - 1]) + arr[0][j];
            dp[1][j] = max(dp[0][j - 1], dp[2][j - 1]) + arr[1][j];
            dp[2][j] = max(dp[0][j - 1], dp[1][j - 1]);
        }
        cout << max(dp[0][N - 1], dp[1][N - 1]) << "\n";
    }
    
    return 0;
}