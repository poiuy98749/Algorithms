#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 999999999;
const int MAX_N = 1001;
const int MAX_COLOR = 3;
int arr[MAX_N][MAX_COLOR];
int dp[MAX_N][MAX_COLOR];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // Dynamic programming 조건을 만족시킨다.
    // dp[n][k] : n번째 집을 k색으로 칠한다고 가정했을 때
    // 최소 비용.
    // 1149번 문제와의 차이는, circular하게 구현해야 한다는 점이다. 즉,
    // 1번과 N번 집을 adjacent하다고 보고 구현해야 한다.
    //
    // n != N인 경우
    // dp[n][0] = min(dp[n - 1][1], dp[n - 2][2]) + arr[n][0];
    // dp[n][1] = min(dp[n - 1][0], dp[n - 2][2]) + arr[n][1];
    // dp[n][2] = min(dp[n - 1][0], dp[n - 2][1]) + arr[n][2];
    // 
    // 3가지 경우를 그냥 따로 고려하면 될 것 같다.
    // 1. 1번째 집을 0번 색상으로 칠했을 때
    //   -> 2번째부터 N번째까지를 dp 규칙대로 채운다.
    //      dp[N][0]은 99999999999로 만들어 준다. 시작 색과 같으면 말이 안되기 때문이다.
    // 2, 3번은 똑같다.
    
    int N;
    cin >> N;
    int result = MAX;

    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < MAX_COLOR; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < 3; i++) {
        // 1번째 index를 i 색상으로 채우는 경우이다.

        // DP initialization -> 1번째 index는 i로만 채울 수 있으므로 나머지는 모두 매우 큰 비용으로 처리한다.
        for (int j = 0; j < 3; j++) {   // 헷갈리지 말자. N은 1부터, 색상은 (0, 1, 2)이다.
            if (j == i) dp[1][i] = arr[1][i];
            else dp[1][j] = MAX;
        }

        // DP
        for (int j = 2; j <= N; j++) {
            dp[j][0] = min(dp[j - 1][1], dp[j - 1][2]) + arr[j][0];
            dp[j][1] = min(dp[j - 1][0], dp[j - 1][2]) + arr[j][1];
            dp[j][2] = min(dp[j - 1][0], dp[j - 1][1]) + arr[j][2];
        }

        // 이제 N번째를 봐야 하는데, 만약 시작과 같은 색상 (i색)이면
        // 아무리 최소여도 소용이 없다.
        for (int j = 0; j <= 2; j++) {
            if (j == i) continue;
            result = min(result, dp[N][j]);
        }
    }

    cout << result << "\n";

    return 0;
}