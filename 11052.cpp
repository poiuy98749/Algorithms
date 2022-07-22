#include <iostream>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // Dynamic programming 조건을 만족시킨다.
    // 1. Optimal substructure
    //    카드 N개를 최대의 금액으로 사고, 만약 카드 K개짜리 팩을
    //    구매한다면, N - K개의 카드 역시 최대의 금액으로 사야 한다.
    // 2. Overlapping subproblems
    //    N개를 살 때 이전의 N - 1, N - 2, ..., 1개를 사는 최대 금액
    //    을 사용할 수 있다.

    int N;
    int* dp;
    cin >> N;
    
    // 배열의 index가 카드의 수를 의미하도록 하기 위해서
    // index 1부터 시작한다.
    int* card_price = new int[N + 1];
    card_price[0] = 0;
    for (int i = 1; i <= N; i++)
        cin >> card_price[i];

    dp = new int[N + 1];    // N개의 카드를 사기 위한 최대의 금액
    dp[0] = 0;
    
    for (int i = 1; i <= N; i++) {
        int max = card_price[i];
        for (int j = 1; j <= i - 1; j++) {
            if (dp[i - j] + dp[j] >= max)
                max = dp[i - j] + dp[j];
        }
        dp[i] = max;
    }
    cout << dp[N] << "\n";
    return 0;

}