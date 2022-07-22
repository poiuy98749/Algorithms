#include <iostream>
#include <cstring>
#include <stack>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
    int T;
    string str;
    stack<char> st;

    cin >> T;
    cin.ignore();

    for (int i = 0; i < T; i++) {
        getline(cin, str);
        str += ' ';

        for (int i = 0; i < str.size(); i++) {
            if (str[i] == ' ') {
                while (!st.empty()) {
                    cout << st.top();
                    st.pop();
                }
                cout << ' ';
            } else {
                st.push(str[i]);
            }
        }
    }
}