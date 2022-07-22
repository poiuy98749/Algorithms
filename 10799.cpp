#include <iostream>
#include <cstring>
#include <stack>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    string input;
    stack<int> st;      // 괄호를 넣었다가 뺐다가 할 stack
    cin >> input;

    int count = 0;
    char prev, current;     // prev는 바로 이전 괄호, current는 지금 뽑은 괄호
    for (int i = 0; i < input.length(); i++) {
        current = input[i];

        if (current == '(') {
            // Open paranthesis는 무조건 push
            st.push('(');
        } else {    // ')'
            if (prev == '(') {  // 바로 직전이 open parenthesis
                // 레이저를 의미
                st.pop();
                count += st.size();
            } else {    // 바로 직전이 close parenthesis
                // 막대가 하나 끝난 것이므로 1을 더해줘야 개수가 맞음
                count += 1;
                st.pop();
            }
        }
        prev = current;
    }

    cout << count << "\n";
    return 0;

}