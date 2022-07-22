#include <iostream>
#include <algorithm>
using namespace std;

const int MAX_LENGTH = 20;

int IntegerToDigitsArray(int arr[], int num) {
    // 123 -> [3, 2, 1, ?, ?, ]...
    // Returns the length of integers.

    int count = 0;
    while (num > 0) {
        arr[count++] = num % 10;
        num /= 10;
    }
    return count;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int arr[MAX_LENGTH];
    int num;
    int length;

    cin >> num;
    length = IntegerToDigitsArray(arr, num);
    
    // 오름차순으로 정렬
    sort(arr, arr + length);
    
    // 거꾸로 출력
    for (int i = length - 1; i >= 0; i--)
        cout << arr[i];
    cout << "\n";
}