#include <iostream>
using namespace std;

int temp[1000001];  // 병합을 할 때에 필요한 임시 배열

void Merge(int arr[], int start, int mid, int end) {
    int result_ptr = 0;
    int p = start;
    int q = mid + 1;

    // 양쪽의 포인터를 비교하며 작은 것을 먼저 임시 배열에 집어넣는다.
    while (p <= mid && q <= end) {
        if (arr[p] <= arr[q])
            temp[result_ptr++] = arr[p++];
        else
            temp[result_ptr++] = arr[q++];
    }

    // 한 쪽이 먼저 끝에 도달한 경우 나머지를 순서대로 집어넣는다.
    while (p <= mid)
        temp[result_ptr++] = arr[p++];
    while (q <= end)
        temp[result_ptr++] = arr[q++];
    
    // 임시 배열에 저장한 결과를 원본 배열로 다시 옮겨야 한다.
    for (int i = 0; i <= end - start; i++)
        arr[start + i] = temp[i];
}

void MergeSort(int arr[], int start, int end) {
    // printf("MergeSort(arr, %d, %d) called!\n", start, end);
    if (end - start <= 0) return;

    int mid = (start + end) / 2;
    
    MergeSort(arr, start, mid);
    MergeSort(arr, mid + 1, end);
    Merge(arr, start, mid, end);
}


int main(void) {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);
    int size;
    cin >> size;
    int arr[size];

    for (int i = 0; i < size; i++)
        cin >> arr[i];
    
    MergeSort(arr, 0, size - 1);

    for (int i = 0; i < size; i++)
        cout << arr[i] << "\n";

    return 0;
}