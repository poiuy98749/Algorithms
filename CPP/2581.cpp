#include <iostream>
#include <cmath>
using namespace std;

int main(void) {
    int num;
    int currentDivisor;

    cin >> num;
    currentDivisor = 2;

    while (num > 1) {
        while (num > 1 && num % currentDivisor == 0) {
            cout << currentDivisor << endl;
            num /=  currentDivisor;
        }
        currentDivisor += 1;
    }
}

