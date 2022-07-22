#include <iostream>
using namespace std;

int GetGCD(int num1, int num2) {
    // 유클리드 호제법을 이용하여 GCD를 구합니다.
    
    while (true) {
        int temp = num1 % num2;
        if (temp == 0) return num2;
        
        num1 = num2;
        num2 = temp;
    }
}

int arr[1000000];

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T_total, T_each;
    long long GCD_sum;
    cin >> T_total;

    for (int i = 0; i < T_total; i++) {
        cin >> T_each;  // 한 줄의 test case 개수
        for (int j = 0; j < T_each; j++) {
            cin >> arr[j];
        }

        // 배열에 저장된 T_each개의 정수들의 조합마다 GCD를 구해서 더합니다.
        GCD_sum = 0;
        for (int i = 0; i < T_each; i++) {
            for (int j = i + 1; j < T_each; j++) {
                // 조합을 구해야 하므로 '이후' index만 체크하면 됩니다.
                GCD_sum += GetGCD(arr[i], arr[j]);
            }
        }

        cout << GCD_sum << "\n";
    }
    return 0;
}