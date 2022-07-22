#include <iostream>
using namespace std;

int getMin(int a, int b, int c, int d) {
    // Return the minimum integer
    int temp1;
    int temp2;

    temp1 = (a > b) ? b : a;
    temp2 = (c > d) ? d : c;

    return (temp1 > temp2) ? temp2 : temp1;
}

int main(void) {
    int x, y, w, h;
    int result;
    cin >> x >> y >> w >> h;

    result = getMin(x, y, w - x, h - y);
    cout << result << endl;
    return 0;
    
}