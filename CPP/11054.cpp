#include <iostream>
using namespace std;

const int MAX_N = 1000;
int arr[MAX_N];
int dp1[MAX_N];     // LIS 저장
int dp2[MAX_N];     // LDS 저장

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 두 가지를 미리 놓으면 쉽게 풀 수 있다.
    // 1. 0부터 k까지의 부분 배열에서의 가장 긴 증가하는 부분 수열
    // 2. k부터 length - 1까지의 부분 배열에서의 가장 긴 감소하는 부분 수열
    // 단, k번째 element를 반드시 포함할 것.

    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
        cin >> arr[i];
    
    // 1. k = 0에서 시작해서 k번째 index를 마지막 index로 하는 증가하는
    // 부분 수열의 길이의 최댓값을 구한다.

    dp1[0] = 1;
    for (int i = 1; i < N; i++) {
        int max = 0;
        for (int j = 0; j < i; j++) {
            if (arr[j] < arr[i] && dp1[j] > max) {
                max = dp1[j];
            }
        }
        dp1[i] = max + 1;
    }

    // 2. k = N - 1에서 시작해서 k번째 index를 첫 index로 하는 가장 긴
    // 감소하는 부분 수열의 길이의 최댓값을 구한다.

    dp2[N - 1] = 1;
    for (int i = N - 2; i >= 0; i--) {
        int max = 0;
        for (int j = i + 1; j < N; j++) {
            if (arr[j] < arr[i] && dp2[j] > max) {
                max = dp2[j];
            }
        }
        dp2[i] = max + 1;
    }

    
    int result = 0;
    for (int i = 0; i < N; i++) {
        if (dp1[i] + dp2[i] > result)
            result = dp1[i] + dp2[i];
    }

    cout << result - 1 << "\n";
    return 0;

}