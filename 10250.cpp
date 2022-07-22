#include <iostream>
using namespace std;

int GetRoomNumber(int height, int width, int number) {
    int vertical;
    int horizontal;

    if (number % height == 0) {
        vertical = height;
        horizontal = number / height;
    } else {
        vertical = number % height;
        horizontal = number / height + 1;
    }
    return vertical * 100 + horizontal;
}

int main(void) {
    int num_of_tc;
    int H, W, N;

    cin >> num_of_tc;
    
    for (int i = 0; i < num_of_tc; i++) {
        cin >> H >> W >> N;
        cout << GetRoomNumber(H, W, N) << endl;
    }
    return 0;
}