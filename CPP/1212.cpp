#include <iostream>
#include <cstring>
using namespace std;

string OctToBin(char c) {
    // 8진수 char을 인자로 받아서 3자리 2진수로 바꾼 뒤 반환한다.
    // '1' -> "001", '0' -> "000", '4' -> '100'

    string result;
    if (c == '0')
        result = "000";
    else if (c == '1')
        result = "001";
    else if (c == '2')
        result = "010";
    else if (c == '3')
        result = "011";
    else if (c == '4')
        result = "100";
    else if (c == '5')
        result = "101";
    else if (c == '6')
        result = "110";
    else if (c == '7')
        result = "111";
    
    return result;
}
int main(void) {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    string str;
    string result = "";
    int first_1_index = 0;
    cin >> str;

    // 수가 0인 경우는 따로 처리해 준다.
    if (str == "0") {
        cout << "0\n";
        return 0;
    }

    // 수가 0이 아닌 경우
    // 첫 번째 index부터 1개씩 char을 가져와서 3개의 char 배열로
    // 바꾼 뒤 result string에 추가해 준다.
    for (int i = 0; i < str.length(); i++)
        result += OctToBin(str[i]);
    
    // 맨 앞에 있는 0들은 출력하면 안되므로 첫 '1'의 위치를 찾는다.
    while (result[first_1_index] == '0')
        first_1_index++;
    
    // 첫 번째 1부터 모두 출력해 준다.
    for (int i = first_1_index; i < result.length(); i++)
        cout << result[i];

    return 0;
}