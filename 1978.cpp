#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int num) {
    int divisor_count = 0;
    int sqrtNum;
    if (num == 1) return false;

    sqrtNum = sqrt(num);
    for (int i = 2; i <= sqrtNum; i++) {
        if (num % i == 0) return false;
    }

    return true;
}

int main(void) {
    int primeCount = 0;
    int num_of_tc;
    cin >> num_of_tc;
    int arr[num_of_tc];
    
    for (int i = 0; i < num_of_tc; i++)
        cin >> arr[i];
    
    for (int i = 0; i < num_of_tc; i++)
        if (isPrime(arr[i]) == true)
            primeCount++;
    
    cout << primeCount << endl;
    return 0;
}