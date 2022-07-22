#include <iostream>
#include <algorithm>
using namespace std;

const int NUM = 9;
int arr[NUM];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int sum = 0;

    for (int i = 0; i < NUM; i++) {
        cin >> arr[i];
        sum += arr[i];
    }
    
    sort(arr, arr + NUM);
    for (int i = 0; i < NUM - 1; i++) {
        for (int j = i + 1; j < NUM; j++) {
            if (sum - (arr[i] + arr[j]) == 100) {
                // 빼야 할 두 난쟁이를 찾은 상황
                // -> i, j번째를 제외하고 출력
                for (int k = 0; k < NUM; k++) {
                    if (k == i || k == j) continue;
                    cout << arr[k] << "\n";
                }
                return 0;
            }
        }
    }

    return 0;
}