#include <iostream>
#include <cstring>
using namespace std;

void strSwap(char** s1, char** s2) {
    char* temp = *s1;
    *s1 = *s2;
    *s2 = temp;
}

void ShowNumber(int* arr, int size) {
    for (int i = 0; i <= size; i++)
        cout << arr[i] << ' ';
    cout << endl;
}

int main(void) {
    char* num1_str = new char[10001];
    char* num2_str = new char[10001];
    char* result[10002];
    int num1[10001];
    int num2[10001];
    int num1_len;
    int num2_len;
    int ptr, sum;

    cin >> num1_str >> num2_str;
    // Make num1_str longer than num2_str
    if (strlen(num2_str) > strlen(num1_str))
        strSwap(&num1_str, &num2_str);
    
    num1_len = strlen(num1_str);
    num2_len = strlen(num2_str);

    num1[0] = 0;    // Carry
    for (int i = 1; i <= num1_len; i++)
        num1[i] = num1_str[i - 1] - '0';
    
    for (int i = 1; i <= num2_len; i++)
        num2[i + (num1_len - num2_len)] = num2_str[i - 1] - '0';
    
    // ShowNumber(num1, num1_len);
    // ShowNumber(num2, num1_len);
    // Iterate through two integer arrays and add them using ptr.
    ptr = strlen(num1_str);
    while (ptr >= 1 && ptr >= num1_len - num2_len + 1) {
        // cout << "ptr is now " << ptr << endl; 
        sum = num1[ptr] + num2[ptr];
        // cout << "sum is " << sum << endl;
        if (sum >= 10) {
            num1[ptr - 1]++;
            sum -= 10;
        }
        num1[ptr--] = sum;
        // cout << "decreased ptr to " << ptr << endl;
    }

    // cout << "Out of while!!!" << endl;
    while (ptr >= 1) {
        if (num1[ptr] >= 10) {
            num1[ptr - 1]++;
            num1[ptr] -= 10;
        }
        ptr--;
    }

    if (num1[0] != 0)
        cout << num1[0];
    
    for (int i = 1; i <= num1_len; i++)
        cout << num1[i];
    cout << endl;

}