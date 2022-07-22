#include <iostream>
using namespace std;

const int MAX_ROWS = 50;
const int MAX_COLS = 50;

int GetDifference(char arr[][MAX_COLS], int startRows, int startCols) {
    // (startRows, startCols)를 왼쪽 상단으로 해서 잘랐을 때 몇 개의 요소가
    // 차이가 나는지를 반환한다.

    int difference_from_B = 0;
    int difference_from_W = 0;

    for (int i = startRows; i <= startRows + 7; i++) {
        for (int j = startCols; j <= startCols + 7; j++) {
            if ((i + j) % 2 == 0) {
                if (arr[i][j] == 'W')   // 합이 짝수면 W시작 -> W, B시작 -> B
                    difference_from_B++;
                else
                    difference_from_W++;
            } else {
                if (arr[i][j] == 'W')   // 합이 홀수면 W시작 -> B, B시작 -> W
                    difference_from_W++;
                else
                    difference_from_B++;
            }
        }
    }
    // 더 작은 차이를 return.
    return (difference_from_B < difference_from_W) ? difference_from_B : difference_from_W;
}

int main(void) {
    char arr[MAX_ROWS][MAX_COLS];
    int difference;     // GetDifference 함수의 return 값을 저장.
    int min = 99999999;     // 현재까지 최소의 차이를 저장.
    int nrows, ncols;
    cin >> nrows >> ncols;

    for (int i = 0; i < nrows; i++) {
        cin >> arr[i];
    }

    // N, M이 주어졌을 때 왼쪽 상단의 좌표는 최대 (N - 8, M - 8) 까지이다.
    for (int i = 0; i <= nrows - 8; i++) {
        for (int j = 0; j <= ncols - 8; j++) {
            difference = GetDifference(arr, i, j);
            if (difference < min)
                min = difference;
        }
    }
    cout << min << endl;
    return 0;
}