#include <iostream>
using namespace std;

int main(void) {
    int x1, y1, x2, y2, x3, y3, x4, y4;
    cin >> x1 >> y1;
    cin >> x2 >> y2;
    cin >> x3 >> y3;

    if (x1 == x2) {     // 1, 2 vetical
        x4 = x3;
        if (y1 == y3)   // 1, 3 horizontal
            y4 = y2;
        else            // 1, 4 horizontal
            y4 = y1;

    } else if (x1 == x3) {    // 1, 3 vertical
        x4 = x2;
        if (y1 == y2) {          // 1, 2 horizontal
            y4 = y3;
        }
        else {                  // 1, 4 horizontal
            y4 = y1;
        }
    }
    else {
        x4 = x1;
        if (y2 == y1)   // 1, 2 horizontal
            y4 = y3;
        else            // 1, 3 horizontal
            y4 = y2;
    }

    cout << x4 << " " << y4 << endl;
}