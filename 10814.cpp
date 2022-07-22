#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

bool comp(pair<int, string> p1, pair<int, string> p2) {
    return p1.first < p2.first;
}

int main(void) {
    ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
    
    int T;      // # of test cases
    int age;
    string name;

    cin >> T;
    vector<pair<int, string>> arr;
    
    for (int i = 0; i < T; i++) {
        cin >> age >> name;
        arr.push_back(pair<int, string>(age, name));
    }
    stable_sort(arr.begin(), arr.end(), comp);

    for (int i = 0; i < T; i++) {
        cout << arr[i].first << " " << arr[i].second << "\n";
    }
    return 0;
}