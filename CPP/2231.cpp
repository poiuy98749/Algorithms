#include <iostream>
using namespace std;

int Decompose(int num) {
    // 인자로 넘겨받은 정수의 분해합을 구한다.
    // decompose(245) = 245 + 2 + 4 + 5 = 256

    int sum = num;
    while (num > 0) {
        sum += num % 10;
        num = num / 10;
    }
    return sum;
}

int main(void) {
    int num;
    int constructor = 0;
    cin >> num;
    
    for (int i = 1; i < num; i++) {
        if (Decompose(i) == num) {
            constructor = i;
            break;
        }
    }
    
    cout << constructor << endl;

    return 0;
}