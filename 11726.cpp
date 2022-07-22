#include <iostream>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    // 맨 오른쪽에 세로로 긴 막대를 몇 개 놓는지에 따라서 경우를 나눌 수 있다.
    // 만약 1개를 세워둔다면 왼쪽에는 바로 직전인 dp[N - 1]만큼의 경우가 존재하게
    // 된다. 다만 이 경우의 수는 오른쪽에 가로로 긴 막대를 위아래로 세우는 경우를
    // 포함하지 않는다. 따라서 dp[N - 2]도 더해주면 된다.
    // 즉, dp[N] = dp[N - 1] + dp[N - 2]  (N >= 3부터 성립)
    // dp[0] = 1로 정해주면 N >= 2부터 성립.

    int num;
    cin >> num;
    int* dp = new int[num];
    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i <= num; i++) {
        dp[i] = dp[i - 1] % 10007 + dp[i - 2] % 10007;
    }

    cout << dp[num] % 10007 << "\n";

    return 0;
}