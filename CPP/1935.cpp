#include <iostream>
#include <cstring>
#include <stack>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    stack<double> st;
    int T;
    int num;
    string str;
    double operand1, operand2;

    cin >> T;
    cin >> str;

    // A, B, C를 arr[0], arr[1], arr[2]에 저장하면 된다.
    // 나중에는 arr['C' - 'A']와 같이 접근하면 편하다.
    int* arr_map = new int[T];
    for (int i = 0; i < T; i++) {
        cin >> num;
        arr_map[i] = num;
    }

    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '+') {
            operand2 = st.top();
            st.pop();
            operand1 = st.top();
            st.pop();
            st.push(operand1 + operand2);
        } else if (str[i] == '-') {
            operand2 = st.top();
            st.pop();
            operand1 = st.top();
            st.pop();
            st.push(operand1 - operand2);
        } else if (str[i] == '*') {
            operand2 = st.top();
            st.pop();
            operand1 = st.top();
            st.pop();
            st.push(operand1 * operand2);
        } else if (str[i] == '/') {
            operand2 = st.top();
            st.pop();
            operand1 = st.top();
            st.pop();
            st.push(operand1 / operand2);
        } else {
            // A, B, C... -> 무조건 push
            st.push(arr_map[str[i] - 'A']);
            // cout << "push " << arr_map[str[i] - 'A'] << "\n";
        }
    }

    printf("%.2f\n", st.top());

}