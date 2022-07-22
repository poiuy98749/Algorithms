#include <iostream>
using namespace std;

bool IsRight(int a, int b, int c) {
    // Return true if for any x, x^2 is
    // the sum of remaining two integers.

    if (a * a == b * b + c * c) return true;
    if (b * b == c * c + a * a) return true;
    if (c * c == a * a + b * b) return true;
    return false;
}

int main(void) {
    int num1, num2, num3;

    while (true) {
        cin >> num1 >> num2 >> num3;
        if (num1 == 0 && num2 == 0 && num3 == 0)
            return 0;
        
        if (IsRight(num1, num2, num3)) cout << "right" << "\n";
        else cout << "wrong" << "\n";
    }
    return 0;
}