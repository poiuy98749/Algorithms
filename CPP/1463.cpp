#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    // Dynamic programming 조건을 만족시킨다.
    // 1. Optimal substructure : 10을 1로 만들려면 2로 나누거나, 1을 빼는 방법이
    //    있는데 최소한 5나 9를 '최소한의 횟수로' 1로 만들어야 한다.
    // 2. Overlapping subproblems : 5나 9를 1로 만들 때 필요한 최소한의 횟수에
    //    1을 더하기만 하면 된다.
    // a[n] : n을 1로 만드는데 필요한 연산의 횟수
    // a[n] = 0 (n == 1)
    //      = min(a[n/2], a[n/3], a[n-1]) + 1 (n % 2 == 0 && n % 3 == 0)
    //      ... (나누어떨어지지 않으면 각각 처리)

    int num;
    cin >> num;
    int* dp = new int[num + 1];
    dp[1] = 0;

    for (int i = 2; i <= num; i++) {
        if (i % 2 == 0 && i % 3 == 0)
            dp[i] = min({dp[i / 3], dp[i / 2], dp[i - 1]}) + 1;
        else if (i % 2 == 0 && i % 3 != 0)
            dp[i] = min({dp[i / 2], dp[i - 1]}) + 1;
        else if (i % 2 != 0 && i % 3 == 0)
            dp[i] = min({dp[i / 3], dp[i - 1]}) + 1;
        else
            dp[i] = dp[i - 1] + 1;
    }

    cout << dp[num] << "\n";

    return 0;
}