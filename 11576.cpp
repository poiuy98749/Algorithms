#include <iostream>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    const int B_MAX_LENGTH = 21;
    int A, B;
    int count;  // Number of digits
    
    cin >> A >> B;
    cin >> count;
    int* arr = new int[count];
    int* result_arr = new int[B_MAX_LENGTH];  // num < 2^20

    for (int i = 0; i < count; i++)
        cin >> arr[i];
    
    // A진법 -> 10진법 -> B진법의 순서로 바꾸는 것이 쉽다.

    // A진법 -> 10진법
    int num = 0;
    for (int i = count - 1, temp = 1; i >= 0; i--) {
        num += temp * arr[i];
        temp *= A;
    }

    // 10진법 -> B진법
    int arr_ptr = 0;
    while (num > 0) {
        result_arr[arr_ptr++] = num % B;
        num /= B;
    }
    // 이제 arr_ptr - 1까지 B진수 숫자가 위치한다.

    // 거꾸로 출력
    for (int i = arr_ptr - 1; i >= 0; i--)
        cout << result_arr[i] << " ";
    
    return 0;
}