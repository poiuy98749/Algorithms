#include <iostream>
using namespace std;

int main(void) {
    int A, B, C;
    int profit;
    int result;
    cin >> A >> B >> C;
    
    if (B >= C) cout << -1 << endl;     // Cannot get any profit
    else {
        profit = C - B;
        result = A / profit + 1;
        cout << result;
    }
    return 0;
}