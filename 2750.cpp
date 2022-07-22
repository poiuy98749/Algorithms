#include <iostream>
using namespace std;

void BubbleSort(int arr[], int size) {
    int i, j, temp;
    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap elements
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main(void) {
    int size;
    cin >> size;
    int arr[size];

    for (int i = 0; i < size; i++)
        cin >> arr[i];
    
    BubbleSort(arr, size);
    
    for (int i = 0; i < size; i++)
        cout << arr[i] << endl;

    return 0;
}