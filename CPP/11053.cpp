#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // Dynamic programming 조건을 만족시킨다.
    // dp[i] : 'i번째 element를 마지막 요소로 갖는 부분 수열의 길이'
    // dp[i]는 arr[i]보다 작은 이전 element들의 dp 최댓값 + 1이다.
    // 즉, dp[i] = max(dp[k1], dp[k2], ...) (arr[k1] < arr[i],
    // arr[k2] < arr[i] ... )

    int length;
    cin >> length;
    int current, max_dp;

    int* arr = new int[length + 1];
    int* dp = new int[length + 1];
    for (int i = 1; i <= length; i++)
        cin >> arr[i];
    for (int i = 1; i <= length; i++)
        dp[i] = 1;
    
    for (int i = 2; i <= length; i++) {
        current = arr[i];
        max_dp = 0;

        for (int j = 1; j <= i - 1; j++) {
            // current보다 작은 element들 중 최대의 dp값을
            // 찾아서 1을 더해주면 된다.
            if (arr[j] < current) {
                max_dp = max(max_dp, dp[j]);
            }
        }

        dp[i] = max_dp + 1;
    }

    for (int i = 1; i <= length; i++)
        cout << dp[i] << " ";
    cout << "\n";

    int result = 1;
    for (int i = 1; i <= length; i++)
        result = max(result, dp[i]);

    cout << result << "\n";
    return 0;
}