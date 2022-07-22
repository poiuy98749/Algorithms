#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int num) {
    int divisor_count = 0;
    if (num == 1) return false;

    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int count;
    int input_num = -1;
    
    // Iterate through the user enters zero.
    while (true) {
        count = 0;  // The number of prime numbers.
        cin >> input_num;
        if (input_num == 0) break;
        for (int i = input_num + 1; i <= 2 * input_num; i++) {
            if (isPrime(i)) count++;
        }
        cout << count << "\n";
    }
    return 0;
}