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
    int num_of_tc;
    int num;
    cin >> num_of_tc;

    for (int i = 0; i < num_of_tc; i++) {
        cin >> num;
        for (int i = num / 2; i >= 2; i--) {
            if (isPrime(i) && isPrime(num - i)) {
                cout << i << " " << num - i << "\n";
                break;
            }
        }
    }
    return 0;
}