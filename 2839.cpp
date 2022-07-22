#include <iostream>
using namespace std;

int main(void) {
    int weight;
    int num_of_5kg;
    int num_of_3kg;
    int remainder;

    cin >> weight;
    num_of_5kg = 0;
    num_of_3kg = 0;
    remainder = 0;

    // With only 5kg
    if (weight % 5 == 0) {
        cout << weight / 5 << endl;
        return 0;
    }

    // First use 5kg at most, and decrease it.
    num_of_5kg = weight / 5;
    remainder = weight % 5;

    while (num_of_5kg >= 0) {
        if (remainder % 3 == 0) {
            cout << num_of_5kg + (remainder / 3) << endl;
            return 0;
        }
        // Decrease the number of 5kg by one.
        num_of_5kg--;
        remainder += 5;
    }
    cout << -1 << endl;
    return 0;
}