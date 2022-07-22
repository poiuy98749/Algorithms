#include <iostream>
#include <stack>
using namespace std;


int main(void) {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int T;
    int num;
    int current;
    int top;

    cin >> T;

    int arr[T];
    stack<int> st;

    for (int i = 0; i < T; i++) {
        cin >> num;
        arr[i] = num;
    }

    if (T <= 1) {
        // 수열의 길이가 1이면 -1을 출력하고 종료
        cout << -1;
        return 0;
    }

    // 스택에 아직 오큰수를 찾지 못한 수의 'index'를 push
    // 다음 index부터 체크하면서 만약 stack의 top보다 해당
    // 배열의 index에 해당하는 수가 크면 해당 수를 pop 하고
    // 해당 index에 해당하는 배열 요소를 바꿔주면 된다.

    st.push(0);     // 0번째 index는 무조건 push
    int arr_ptr = 1;    // arr[1]부터 체크

    while (arr_ptr < T) {
        current = arr[arr_ptr];
        // cout << "-------------------------------\n";
        // cout << "Current : " << current << "\n";
        while (!st.empty()) {
            // 스택에 남아있는 요소가 있는 동안
            top = st.top();
            // cout << "Stack top index : " << top << "\n";
            // cout << "Stack top element : " << arr[top] << "\n";
            if (current > arr[top]) {
                // current가 stack의 top index 수의 오큰수
                arr[top] = current;
                st.pop();
                // cout << "Current가 더 크므로 오큰수 발견, pop\n";
            } else {
                // current가 더 작으면 while문 탈출
                // cout << "Current가 더 작으므로 break\n";
                break;
            }
        }
        // current의 오큰수도 나중에 찾아야 하므로 push
        st.push(arr_ptr);
        arr_ptr++;
    }

    while (!st.empty()) {
        // 스택에 남아있는 index들은 오큰수가 존재 X
        top = st.top();
        arr[top] = -1;
        st.pop();
    }
    
    for (int i = 0; i < T; i++)
        cout << arr[i] << " ";

    return 0;
}