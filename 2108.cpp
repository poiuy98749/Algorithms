#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

const int MAX = 8001;
int mode_arr[MAX]; // -4000 to 0, -3000 to 1000, 0 to 4000, 1000 to 5000...

int GetAverage(int arr[], int size) {
    int sum = 0;
    double average;
    for (int i = 0; i < size; i++)
        sum += arr[i];
    
    average = sum / (size * 1.0);
    if (average >= 0)
        return round(average);
    else
        return (-1) * round((-1) * average);
}

int GetMaxIndex(int arr[], int size) {
    int max_index = 0;
    int max_value = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max_value) {
            max_index = i;
            max_value = arr[i];
        }
    }
    return max_index;
}

int GetMedian(int arr[], int size) {
    sort(arr, arr + size);
    return arr[size / 2];
}

int GetMode(int arr[], int size) {
    int max_index;

    // 도수 배열을 0으로 초기화한다.
    for (int i = 0; i < MAX; i++)
        mode_arr[i] = 0;
    
    // 도수를 모두 구한다.
    for (int i = 0; i < size; i++) {
        // printf("mode_Arr[arr[%d](%d) + 4000]++\n", i, arr[i]);
        mode_arr[arr[i] + 4000]++;
    }
    
    // 최대 도수를 갖는 최소 index를 구한다.
    max_index = GetMaxIndex(mode_arr, MAX);
    // cout << "Max_index: " << max_index << endl;

    // 해당 index 뒤에 같은 값이 나오면 그 값이 두 번째로 작은 값이다.
    for (int i = max_index + 1; i < MAX; i++) {
        if (mode_arr[i] == mode_arr[max_index]) {
            // printf("mode_arr[%d](%d) == mode_arr[%d](%d)\n", i, mode_arr[i],
            // max_index, mode_arr[max_index]);
            return (i - 4000);
        }
    }
    // 유일한 최빈값인 경우
    return (max_index - 4000);
}

int GetRange(int arr[], int size) {
    sort(arr, arr + size);
    return (arr[size - 1] - arr[0]);
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    // int arr1[] = {1, 3, 8, -2, 2};
    // int arr2[] = {4000};
    // int arr3[] = {-1, -2, -3, -1, -2};
    // int arr4[] = {1, 3, 1, 1, 3, 3, 7, 5, 4};

    // cout << "Average\n";
    // cout << GetAverage(arr1, sizeof(arr1) / sizeof(int)) << "\n";
    // cout << GetAverage(arr2, sizeof(arr2) / sizeof(int)) << "\n";
    // cout << GetAverage(arr3, sizeof(arr3) / sizeof(int)) << "\n";

    // // cout << "\nMedian\n";
    // // cout << GetMedian(arr1, sizeof(arr1) / sizeof(int)) << "\n";
    // // cout << GetMedian(arr2, sizeof(arr2) / sizeof(int)) << "\n";
    // // cout << GetMedian(arr3, sizeof(arr3) / sizeof(int)) << "\n";

    // cout << "\nMode\n";
    // cout << GetMode(arr1, sizeof(arr1) / sizeof(int)) << "\n";
    // cout << GetMode(arr2, sizeof(arr2) / sizeof(int)) << "\n";
    // cout << GetMode(arr3, sizeof(arr3) / sizeof(int)) << "\n";

    // cout << "\nRange\n";
    // cout << GetRange(arr1, sizeof(arr1) / sizeof(int)) << "\n";
    // cout << GetRange(arr2, sizeof(arr2) / sizeof(int)) << "\n";
    // cout << GetRange(arr3, sizeof(arr3) / sizeof(int)) << "\n";

    int TC;
    cin >> TC;
    int arr[TC];

    for (int i = 0; i < TC; i++)
        cin >> arr[i];
    
    cout << GetAverage(arr, TC) << "\n";
    cout << GetMedian(arr, TC) << "\n";
    cout << GetMode(arr, TC) << "\n";
    cout << GetRange(arr, TC) << "\n";
    return 0;
    
}