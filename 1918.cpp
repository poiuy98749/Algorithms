#include <iostream>
#include <stack>
#include <cstring>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    stack<char> st;
    string str;
    cin >> str;
    char current;

    // 기본적으로 스택은 LIFO이므로 우선순위가 높은 operator를
    // 나중에 쌓으면 이를 먼저 연산하게 된다는 아이디어이다.
    // 또한 괄호의 경우에는 오른쪽 괄호가 등장하면 왼쪽 괄호가
    // 등장할 때까지 있던 모든 operator를 pop 해주면 이를 먼저
    // 연산하는 효과를 낼 수 있다.

    for (int i = 0; i < str.length(); i++) {
        current = str[i];
        if (current >= 'A' && current <= 'Z') {
            // Operand인 경우에는 무조건 출력
            cout << current;
        } else if (current == '+' || current == '-') {
            // +나 -는 우선순위가 가장 낮다.
            while (!st.empty() && st.top() != '(') {
                // 우선순위가 낮은 것이 왔으므로 먼저 할 연산들을
                // pop해서 해줘야 하는 것이다. 다만 괄호 open 뒤까지만
                // 해줘야 한다.
                cout << st.top();
                st.pop();
            }
            st.push(current);   // current 연산은 나중에 우선순위에 따라 처리
        } else if (current == '*' || current == '/') {
            // *나 /는 우선순위가 괄호를 제외하면 가장 높다.
            // 따라서 이미 있던 *나 /는 모두 pop을 해주고 스택에 쌓아주면 알아서 
            // 나중에 가장 먼저 연산된다. (LIFO)
            
            while (!st.empty() && (st.top() == '*' || st.top() == '/')) {
                cout << st.top();
                st.pop();
            }
            st.push(current);
        } else if (current == '(') {
            st.push('(');
        } else {
            // close paranthesis의 경우에는 open paranthesis까지 모두 pop을
            // 하며 출력한다. 이렇게 해도 되는 이유는 이미 연산자 우선순위에 따라
            // 스택에 쌓여있기 때문이다.
            while (st.top() != '(') {
                cout << st.top();
                st.pop();
            }
            st.pop();   // 마지막 남은 ( 를 pop 한다. ) 는 push할 필요가 없다.
        }
    }

    // 스택에 남아있는 연산자들을 모두 pop 하며 출력해 준다.
    while (!st.empty()) {
        cout << st.top();
        st.pop();
    }
    return 0;
}