#include <iostream>
using namespace std;

int getMaxDistance(int num) {
    // num >= 4
    // Return the maximum distance among moves
    // ex: 1, 2, 3, 2, 2, 1 -> 3 / 1, 2, 3, 4, 3, 2, 1 -> 4...
    // 1 + 2 + ... + k + (k - 1) + ... + 1 = k^2
    long long result = 2;
    while (result * result <= num)
        result += 1;
    
    return result - 1;
}
int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int num_of_tc;
    long long x, y;
    long long max;    // minimum distance k where (y - x) <= 1 + 2 + ... + k + (k - 1) + ... + 1
    long long remains;
    long long num_of_added_numbers;
    cin >> num_of_tc;

    for (int i = 0; i < num_of_tc; i++) {
        // cout << "---------------------------" << endl;
        cin >> x >> y;
        if (y - x <= 3) {   // Handle edge cases
            cout << y - x << endl;
            continue;
        }
        max = getMaxDistance(y - x);
        // cout << "max: " << max << endl;
        if (max * max == y - x) {  // 1 + 2 + 1, 1 + 2 + 3 + 2 + 1, ...
            // cout << "square number!" << endl;
            cout << max * 2 - 1 << endl;    // 2N - 1 steps
            continue;
        }

        // Add remaining distance among numbers.
        remains = (y - x) - (max * max);
        num_of_added_numbers = (remains - 1) / max + 1;
        // cout << "remains: " << remains << endl;
        // cout << "number of added numbers: " << num_of_added_numbers << endl;

        cout << max * 2 - 1 + num_of_added_numbers << endl;
    }
    return 0;
}