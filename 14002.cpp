#include <iostream>
using namespace std;

const int MAX_N = 1000;
int arr[MAX_N];
int dp[MAX_N];
int link[MAX_N];
int result[MAX_N];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // Dynamic programming 조건을 만족시킨다.
    // dp[i] : 'i번째 index의 element를 마지막으로 선택했을 때, 
    // 가장 긴 증가하는 부분 수열의 최대 길이
    // dp[i] = max(dp[x1], dp[x2], ...), 단 arr[x1] < arr[i],
    // arr[x2] < arr[i], ...
    // 수열 자체도 출력해야 하므로 별도의 배열 link를 선언하여
    // '직전 element의 index를 저장'한다.

    int N;
    cin >> N;
    
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    
    // DP initialization
    dp[0] = 1;
    
    // DP
    for (int i = 1; i < N; i++) {
        int current = arr[i];
        int dp_max = 0;
        int dp_max_index = -1;
        for (int j = 0; j < i; j++) {
            if (arr[j] < current && dp[j] > dp_max) {
                dp_max = dp[j];
                dp_max_index = j;
            }
        }

        dp[i] = dp_max + 1;
        link[i] = dp_max_index;
    }

    // Find dp max and print it out
    int max_dp = dp[0];
    int max_dp_index = 0;

    for (int i = 0; i < N; i++) {
        if (dp[i] > max_dp) {
            max_dp_index = i;
            max_dp = dp[i];
        }
    }

    cout << max_dp << "\n";

    result[0] = max_dp_index;
    for (int i = 0; i < max_dp - 1; i++) {
        result[i + 1] = link[max_dp_index];
        max_dp_index = link[max_dp_index];
    }

    for (int i = max_dp - 1; i >= 0; i--)
        cout << arr[result[i]] << " ";
    cout << "\n";

    return 0;
}