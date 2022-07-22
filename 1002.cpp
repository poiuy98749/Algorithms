#include <iostream>
using namespace std;

int DistanceSquared(int x1, int y1, int x2, int y2) {
    int dx_squared;
    int dy_squared;

    dx_squared = (x1 - x2) * (x1 - x2);
    dy_squared = (y1 - y2) * (y1 - y2);

    return dx_squared + dy_squared;
}

void SwapPosition(int* x1, int* y1, int* r1, int* x2, int* y2, int* r2) {
    // Make r1 always bigger than r2.
    int temp_x1, temp_y1, temp_r1;
    temp_x1 = *x1; temp_y1 = *y1; temp_r1 = *r1;

    // Swap
    *x1 = *x2;
    *y1 = *y2;
    *r1 = *r2;

    *x2 = temp_x1;
    *y2 = temp_y1;
    *r2 = temp_r1;
}

int main(void) {
    int num_of_tc;
    int x1, y1, r1, x2, y2, r2;
    int distance_squared;
    int sum_of_radius_squared;
    int sub_of_radius_squared;

    cin >> num_of_tc;
    
    for (int i = 0; i < num_of_tc; i++) {
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
        if (x1 == x2 && y1 == y2 && r1 == r2) {     // Infinite
            cout << -1 << "\n";
            continue;
        }

        // Swap two circle if r1 < r2
        if (r1 < r2) SwapPosition(&x1, &y1, &r1, &x2, &y2, &r2);

        distance_squared = DistanceSquared(x1, y1, x2, y2);
        sum_of_radius_squared = r1 * r1 + r2 * r2 + 2 * r1 * r2;
        sub_of_radius_squared = r1 * r1 + r2 * r2 - 2 * r1 * r2;

        if (distance_squared == sum_of_radius_squared) {
            cout << "1\n";
        } else if (distance_squared > sum_of_radius_squared) {
            cout << "0\n";
        } else {
            if (distance_squared == sub_of_radius_squared) {
                cout << "1\n";
            } else if (distance_squared < sub_of_radius_squared) {
                cout << "0\n";
            } else {
                cout << "2\n";
            }
        }
    }
    
}