#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int T;
    cin >> T;

    // 배열, 스택 초기화
    int arr[T];
    stack<int> st;
    vector<char> buffer;
    int current;
    int last_pushed_element = 0;

    // 배열에 수열 저장
    for (int i = 0; i < T; i++) {
        cin >> arr[i];
    }

    // 1부터 현재 수열 ak까지 stack에 push
    // ak를 push하고 나서는 비교하며 pop
    int ptr = 0;        // 수열의 항을 가리키는 카운터 변수
    while (ptr < T) {
        // cout << "current = arr[" << ptr << "++]\n";
        current = arr[ptr++];
        if (st.empty()) {
            // cout << "stack is Empty!\n";
            if (current > last_pushed_element) {
                // cout << "current(" << current << ") > last pushed(" << last_pushed_element << ")\n";
                for (int i = last_pushed_element + 1; i <= current; i++) {
                    // cout << i;
                    st.push(i);
                    buffer.push_back('+');
                }
                last_pushed_element = st.top();
                // cout << st.top();
                buffer.push_back('-');
                st.pop();
            } else {
                buffer.push_back('0');
                break;
            }
        } else {
            if (current == st.top()) {
                // cout << "current(" << current << ") == st.top(" << st.top() << ")\n";
                // cout << st.top();
                buffer.push_back('-');
                st.pop();
            } else if (current > last_pushed_element) {
                // cout << "current(" << current << ") > st.top(" << st.top() << ")\n";
                for (int i = last_pushed_element + 1; i <= current; i++) {
                    // cout << i;
                    st.push(i);
                    buffer.push_back('+');
                }
                last_pushed_element = st.top();
                // cout << st.top();
                buffer.push_back('-');
                st.pop();
            } else {
                buffer.push_back('0');
                break;
            }
        }
    }
    if (buffer[buffer.size() - 1] == '0') cout << "NO\n";
    else {
        for (int i = 0; i < buffer.size(); i++) {
            cout << buffer[i] << "\n";
        }
    }
}