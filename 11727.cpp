#include <iostream>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 기본적으로 dp[N]이 dp[N - 1]로 표현이 가능하다. 다만 이는 오른쪽에
    // 가로 막대 2개를 위아래로 세워놓는 경우, 정사각형 상자를 오른쪽에 세워두는
    // 경우를 포함하지 못하므로 이를 세주면 되는데, 이는 모두 dp[N - 1]가지이므로
    // dp[N] = dp[N - 1] + 2 * dp[N - 2]가 된다.
    // dp[0] = 1, dp[1] = 1로 해주면 N >= 2에 대해서 성립하도록 할 수 있다.

    int num;
    cin >> num;
    int* dp = new int[num + 1];
    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i <= num; i++)
        dp[i] = dp[i - 1] % 10007 + (2 * dp[i - 2]) % 10007;
    
    cout << dp[num] % 10007 << "\n";
    return 0;
}