#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double EuclideanArea(int radius) {
    return M_PI * radius * radius;
}

double TaxiArea(int radius) {
    return 2.0 * radius * radius;
}

int main(void) {
    int radius;
    cin >> radius;
    cout << fixed << setprecision(6) << EuclideanArea(radius) << "\n";
    cout << fixed << setprecision(6) << TaxiArea(radius) << "\n";
    return 0;
}
