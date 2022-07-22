#include <iostream>
using namespace std;

int main(void) {
    int input;
    int layer;      // max(k) where 1 + 2 + 3 + ... + k <= input
    int position;   // Nth position in same layer (starting from top right)
    int cummulative_sum;    // 1 + 2 + 3 + ... + k
    int numerator;
    int denominator;

    cin >> input;
    layer = 1;
    cummulative_sum = 0;

    // Get layer (k)
    while (cummulative_sum < input) {
        cummulative_sum += layer;
        layer += 1;
    }
    layer--;

    // Get position, which is also numerator
    position = layer - (cummulative_sum - input);

    // Get numerator and denominator
    numerator = position;
    denominator = layer - numerator + 1;

    if (layer % 2 == 0) {
        cout << numerator << "/" << denominator << "\n";
    } else {
        cout << denominator << "/" << numerator << "\n";
    }
    

    return 0;
}