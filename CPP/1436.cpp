#include <iostream>
using namespace std;

int MAX_LENGTH = 99999;

bool Has666(int num) {
    // Convert the integer number into int array.
    // 12345 -> {1, 2, 3, 4, 5}
    int length = 0;
    int i = 0;
    int count_6 = 0;
    int num_int[MAX_LENGTH];

    while (num > 0) {
        num_int[length++] = num % 10;
        num /= 10;
    }
    
    while (i < length) {
        // cout << "----------------------------" << endl;
        // cout << "Current i : " << i << endl;
        // cout << "num_int[i] : " << num_int[i] << endl;
        if (num_int[i] == 6) {
            count_6++;
            i++;
        } else {
            count_6 = 0;
            i++;
        }
        // cout << "count_6 : " << count_6 << endl;
        if (count_6 >= 3) return true;
    }
    return false;
}

int main(void) {
    int num;
    int current_num;
    int count;

    current_num = 0;
    cin >> num;
    count = 0;

    while (count < num) {
        if (Has666(current_num)) count++;
        current_num++;
    }

    cout << current_num - 1 << endl;
    return 0;
}