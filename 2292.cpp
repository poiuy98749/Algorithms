#include <iostream>
using namespace std;

int main(void) {
    int input;
    cin >> input;
    int cummulative_sum = 1;        // d = 6인 계차수열이므로 계속 더해나가야 함.
    int result = 1;     // 한 layer씩 더할 때마다 1씩 증가.
    int difference = 6;     // layer 사이의 간격 자체도 6씩 계속 증가.

    if (input == 1) {
        cout << 1;
        return 0;
    }

    while (cummulative_sum < input) {
        result += 1;
        cummulative_sum += difference;
        difference += 6;
    }

    cout << result << endl;
    return 0;
}