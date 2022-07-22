#include <iostream>
using namespace std;

int GetGCD(int num1, int num2) {
    // 유클리드 호제법을 이용하여 GCD를 구합니다.
    
    while (true) {
        int temp = num1 % num2;
        if (temp == 0) return num2;
        
        num1 = num2;
        num2 = temp;
    }
}

int main(void) {

    // S로부터 A1, A2, ..., An까지 떨어진 거리를 각각 d1, d2, ..., dn이라고 하면
    // d1 ~ dn의 GCD가 결국 답이 된다. 점프해서 갈 수 있다는 것은 알고보면 점프의
    // 간격의 배수만큼 떨어져 있다는 의미이기 때문이다.

    int GCD;
    int N, S;   // N은 동생의 수, S는 수빈의 위치
    cin >> N >> S;

    int* arr = new int[N];      // 동생의 위치 배열 생성, 초기화
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    
    // 배열의 각 요소들을 S로부터 떨어진 거리로 바꾸어 준다.
    for (int i = 0; i < N; i++) {
        if (arr[i] < S)
            arr[i] = S - arr[i];
        else
            arr[i] = arr[i] - S;
    }

    // 간격들의 GCD를 구해 준다. 단순히 loop를 이용하면 여러 수의 GCD를
    // 구해줄 수 있다. 단, 동생이 1명인 경우는 따로 처리해준다.
    if (N == 1) {
        cout << arr[0] << "\n";
        return 0;
    }

    GCD = GetGCD(arr[0], arr[1]);
    for (int i = 2; i < N; i++) {
        GCD = GetGCD(GCD, arr[i]);
    }

    cout << GCD << "\n";
}