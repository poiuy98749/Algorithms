#include <iostream>
#include <cstring>
using namespace std;

int BinToOct(string &str, int start_index) {
    // 길이가 이미 3의 배수로 만들어진 문자열, 앞에서 몇 번째 8진수
    // 숫자가 될 것인지를 인자로 받아서 해당하는 8진수 숫자를 return
    
    int sum = 0;
    sum += (str[start_index] - '0') * 4;
    sum += (str[start_index + 1] - '0') * 2;
    sum += (str[start_index + 2] - '0') * 1;
    return sum;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str;
    cin >> str;

    // 숫자를 3개씩 쪼개야 하는데 나누어 떨어지지 않으면 불편하므로 맨 앞에
    // 0을 적당히 추가해 준다.
    if (str.length() % 3 == 1) {
        // 1_101_110 과 같은 경우 -> 0 2개 추가
        str = "00" + str;
    } else if (str.length() % 3 == 2) {
        // 10_101_110과 같은 경우 -> 0 1개 추가
        str = "0" + str;
    }

    // 문자열의 앞에서부터 3개씩 binary digit을 가져온 뒤
    // 8진수로 바꾸어 출력해 준다.
    for (int i = 0; i < str.length(); i += 3) {
        cout << BinToOct(str, i);
    }

    return 0;
}