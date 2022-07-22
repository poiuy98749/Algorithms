#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
    int T;
    int input;
    int count;

    cin >> T;

    // Initialize a vector and reserve space for T elements.
    vector<int> arr(T);

    // Store int elements into a vector.
    for (int i = 0; i < T; i++) {
        cin >> arr[i];
    }

    // Copy the vertor.
    vector<int> vector_copy(arr);

    // Sort the vector in ascending order and erase duplicates.
    sort(vector_copy.begin(), vector_copy.end());
    vector_copy.erase(unique(vector_copy.begin(), vector_copy.end()), vector_copy.end());
    
    // Print
    for (int i = 0; i < arr.size(); i++) {
        auto index = lower_bound(vector_copy.begin(), vector_copy.end(), arr[i]);
        cout << index - vector_copy.begin() << ' ';
    }

}