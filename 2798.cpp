#include <iostream>
using namespace std;

int main(void) {
    int arr_card[100];
    int N, M;
    int sum;                       // All possible combinations of (x, y, z).
    int difference = 99999999;     // Min{M - sum} for all possible sum, not considering the cases (sum > M)
    cin >> N >> M;

    for (int i = 0; i < N; i++)
        cin >> arr_card[i];
    

    // Use triple for-loop to get all possible combinations -> O(N^3)
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            for (int k = j + 1; k < N; k++) {
                sum = arr_card[i] + arr_card[j] + arr_card[k];
                if (sum > M) continue;      // Do not consider this case.                
                if (M - sum < difference)   // Relaxation
                    difference = M - sum;
            }
        }
    }
    
    cout << M - difference << endl;
}