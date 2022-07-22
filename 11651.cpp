#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(const pair<int, int>& p1, const pair<int, int>& p2) {
    if (p1.second < p2.second) {
        return true;
    } else if (p1.second == p2.second) {
        if (p1.first < p2.first) {
            return true;
        } else if (p1.first == p2.first) {
            return false;
        } else {
            return false;
        }
    } else {
        return false;
    }
}

int main(void) {
    ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

    vector<pair<int, int>> arr;
    int T;
    int x, y;
    cin >> T;


    // Store points into the vector.
    for (int i = 0; i < T; i++) {
        cin >> x >> y;
        arr.push_back(pair<int, int>(x, y));
    }
    
    // Sort
    sort(arr.begin(), arr.end(), compare);

    // Print sorted vector.
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i].first << " " << arr[i].second << "\n";

}