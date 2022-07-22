#include <iostream>
using namespace std;

void PrintStar(int num, int column, int row) {
    int blank_first, blank_last;

    if (num == 1) {
        cout << '*';
        return;
    }
    if (num == 3) {
        if (row == 1 && column == 1) cout << ' ';
        else cout << '*';

        return;
    }
    
    blank_first = num / 3;
    blank_last = blank_first + (num / 3) - 1;

    if (row >= blank_first && row <= blank_last &&
        column >= blank_first && column <= blank_last) {
            cout << ' ';
    } else {
        PrintStar(num / 3, row % (num / 3), column % (num / 3));
    }
}

int main(void) {
    int num;
    cin >> num;

    for (int i = 0; i <= num - 1; i++) {
        for (int j = 0; j <= num - 1; j++) {
            PrintStar(num, i, j);
        }
        if (i != num - 1)
            cout << "\n";
    }
}
