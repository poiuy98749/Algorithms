#include <iostream>
using namespace std;

int factorial(int n) {
    if (n <= 1) return 1;
    else {
        return n * factorial(n - 1);
    }
}
int main(void) {
    int num;
    cin >> num;

    cout << factorial(num) << "\n";
    
    return 0;
}