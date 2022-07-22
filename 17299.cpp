#include <iostream>
#include <stack>
using namespace std;

int GetMax(int arr[], int size) {
    // index 배열을 쓰기 위해서는 최댓값을 알아야 한다.
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

void SetFrequency(int arr1[], int size1, int arr2[], int size2) {
    // 배열 arr1의 요소들의 빈도를 구해서 arr2에 저장한다.
    // 시간 복잡도를 줄이기 위해서 index 배열을 활용한다.
    
    // index 배열을 우선 모두 0으로 초기화한다.
    for (int i = 0; i < size2; i++)
        arr2[i] = 0;

    // 빈도를 계산한다. O(size1)의 linear time으로 가능하다.
    for (int i = 0; i < size1; i++)
        arr2[arr1[i]]++;
}

int main(void) {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    stack<int> st;
    int T;
    int max;    // 빈도 배열을 만들기 위한 최댓값 
    cin >> T;

    int current_ptr = 1;
    int current_element;
    int current_frequency;
    int top_index;
    int top_frequency;
    
    int* arr = new int[T];
    for (int i = 0; i < T; i++)
        cin >> arr[i];
    
    // 배열의 최댓값이 M이면 크기가 M + 1인 index 배열을
    // 생성하고 빈도를 집어넣는다.
    max = GetMax(arr, T);
    int* arr_frequency = new int[max + 1];
    SetFrequency(arr, T, arr_frequency, max + 1);

    // 이제 arr[i]의 빈도를 보려면 arr_frequency(arr[i])를
    // 보면 되므로 O(1)에 접근이 가능하다.

    // 수열의 길이가 1이면 무조건 -1을 출력하고 종료한다.
    // 1이 아니면 일단 arr[0]을 스택에 넣는다.
    if (T == 1) {
        cout << "-1\n";
        return 0;
    }

    st.push(0);

    // i = 1부터 current에 arr[i]를 넣는다. 그리고 stack의
    // top index의 frequency가 arr[i]의 frequency인 
    // arr_frequency(arr[i])보다 작으면 오등큰수를 발견한
    // 것이므로 오등큰수 배열에 current를 넣어준다.

    while (current_ptr < T) {
        current_element = arr[current_ptr];
        current_frequency = arr_frequency[current_element];
        // cout << "---------------------------------------\n";
        // cout << "Current_ptr : " << current_ptr << "\n";
        // cout << "Current_element : " << current_element << "\n";
        // cout << "Current_frequency : " << current_frequency << "\n";

        while (!st.empty()) {
            top_index = st.top();
            top_frequency = arr_frequency[arr[top_index]];
            // cout << "Top_index : " << top_index << "\n";
            // cout << "Top_frequency : " << top_frequency << "\n";
            if (current_frequency > top_frequency) {
                // 오등큰수 발견
                // cout << "NGF found!\n";
                arr[top_index] = current_element;
                st.pop();
            } else {
                // cout << "NGF not found!\n";
                break;
            }
        }

        st.push(current_ptr);
        current_ptr++;
    }

    while (!st.empty()) {
        top_index = st.top();
        arr[top_index] = -1;
        st.pop();
    }

    for (int i = 0; i < T; i++)
        cout << arr[i] << " ";
    return 0;
}