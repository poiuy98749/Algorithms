#include <iostream>
#include <cstring>
#include <stack>
using namespace std;

bool IsVPS(string &str) {
    stack<char> st;
    char current;

    int ptr = 0;
    int size = str.size();

    while (ptr < size) {
        current = str[ptr++];
        if (current == '(') st.push(current);   // ( 이면 무조건 push
        else {      // ) 인 경우
            if (st.empty()) return false;       // 닫을 괄호가 없으니 false
            else {
                st.pop();
            }
        }
    }
    if (!st.empty()) return false;     // 스택에 남은 괄호가 있으면 false
    return true;
}

int main(void) {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    bool vps;
    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {
        string str;
        cin >> str;
        vps = IsVPS(str);
        if (vps) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}