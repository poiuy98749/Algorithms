#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    string result = "";
    int num;
    int q, r;   // 몫, 나머지
    cin >> num;

    // 0일 경우의 예외 처리
    if (num == 0) {
        cout << "0\n";
        return 0;
    }

    while (num != 1) {
        // -2로 계속 나누면서 나머지를 string 배열에 추가한다.
        // 앞에서부터 추가하고 나중에 뒤집으면 된다.
        // num이 양수인지 음수인지에 따라서 나눠야 한다.
        // 나머지가 반드시 0 또는 1이어야 하기 때문이다.

        // cout << "-----------------------------------\n";
        // cout << "num : " << num << "\n";
        if (num > 0) {
            // 양수인 경우에는 몫, 나머지가 모두 정상적으로 나온다.
            result += (char)('0' + (num % -2));   // 1 -> '1', 0 -> '0'
            num /= -2;
        } else {
            // 음수인 경우에는 나누어떨어지면 문제가 없다.
            if (num % -2 == 0) {
                result += (char)('0' + (num % -2));   // 1 -> '1', 0 -> '0'
                num /= -2;
            } else {
                // 나누어떨어지지 않으면 나머지가 음수가 나오게 된다. 따라서
                // 몫에 1을 더해주고 나머지는 무조건 1로 해주면 된다.
                result += '1';
                num = (num / -2) + 1;
            }
        }
    }
    // 마지막에 1 하나를 더해야 한다.
    result += '1';

    // 결과를 거꾸로 출력한다.
    for (int i = result.length() - 1; i >= 0; i--)
        cout << result[i];
    cout << "\n";

    return 0;
}