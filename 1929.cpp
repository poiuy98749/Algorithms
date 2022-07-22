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

    int M, N;
    cin >> M >> N;

    for (int i = M; i <= N; i++) {
        if (isPrime(i)) cout << i << "\n";
    }
    return 0;
}