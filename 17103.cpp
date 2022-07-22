#include <iostream>
using namespace std;

void FindPrime(bool arr[], int to_index) {
    // arr의 index들을 정수로 보고 해당 수가 소수이면 true,
    // 아니면 false로 초기화합니다.

    // 우선 모두 true로 초기화
    for (int i = 0; i <= to_index; i++) {
        arr[i] = true;
    }

    // 2부터 sqrt(to_index)까지 돌면서 만약 이미 false가 되었다면
    // 넘어가고, true라면 해당 수의 배수들을 모두 false로 바꾼다.
    for (int i = 2; i * i <= to_index; i++) {
        if (!arr[i]) continue;

        for (int j = 2 * i; j <= to_index; j += i) {
            arr[j] = false;
        }
    }
}

bool arr[1000001];

int main(void) {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    // 에라스토테네시의 체를 이용하여 1부터 1,000,000 사이의 소수를 판별한다.
    FindPrime(arr, 1000000);

    int T;
    int num;
    int count;
    cin >> T;

    for (int i = 0; i < T; i++) {
        cin >> num;
        count = 0;

        // 파티션을 찾는데 2부터 num / 2까지만 봐주면 된다.
        for (int j = 2; j <= num / 2; j++) {
            if (arr[j] & arr[num - j]) {
                // cout << "(" << j << ", " << num - j << ")\n";
                count++;
            }
        }
        cout << count << "\n";
    }

    

    return 0;
}