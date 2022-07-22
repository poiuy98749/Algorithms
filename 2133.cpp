#include <iostream>
using namespace std;

const int MAX_N = 30;
int dp[MAX_N + 1];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // Dynamic programming 조건을 만족시킨다.
    // dp[n] : 3 x n 크기의 벽을 타일로 채우는 경우의 수
    // 일단 n이 홀수면 넓이가 홀수가 되므로 애초에 불가능하다.
    // n이 짝수면 가로 길이를 2씩 늘려가며 3 X 2 크기의 벽을 채우는
    // 경우의 수인 3을 곱해주면 된다. 즉 dp[n] = dp[n - 2] * 3
    //
    // 그런데 조금만 더 생각해보면 3을 곱하기만 해서 표현이 되지 않는
    // 부분이 있다. 경계 부분에 가로로 길게 늘어놓는 경우를 생각해 보면
    // 2가지가 있는데, 각각에 대해서 dp[n - 4]를 곱해줘야 한다.

    int N;
    cin >> N;

    // DP initialization
    dp[0] = 1; dp[1] = 0; dp[2] = 3; dp[3] = 0;

    // DP
    if (N % 2 != 0) {
        cout << "0\n";
        return 0;
    }

    for (int i = 4; i <= N; i++) {
        if (i % 2 != 0) dp[i] = 0;
        else {
            dp[i] = 3 * dp[i - 2] + 2 * dp[i - 4];
        }
    }

    cout << dp[N] << "\n";
}