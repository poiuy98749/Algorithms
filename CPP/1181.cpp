    #include <iostream>
    #include <vector>
    #include <cstring>
    #include <algorithm>

    using namespace std;

<<<<<<< HEAD
    bool compareStr(string& s1, string& s2) {
        if (s1.length() < s2.length()) {
            return true;
        } else if (s1.length() == s2.length()) {
            return s1 < s2;
=======
bool compareStr(string& s1, string& s2) {
    if (s1.length() < s2.length()) {
        return true;
    } else if (s1.length() == s2.length()) {
        if (s1.compare(s2) < 0) {
            return true;
>>>>>>> e65e35d684d7772d0e95df08fb7719be23542dca
        } else {
            return false;
        }
    }

    int main(void) {
        ios::sync_with_stdio(0);
        cin.tie(0); cout.tie(0);
        int T;  // The number of test cases
        string temp;

        cin >> T;
        vector<string> arr;
        
        for (int i = 0; i < T; i++) {
            cin >> temp;
            arr.push_back(temp);
        }

        // 정렬
        sort(arr.begin(), arr.end(), compareStr);

        // 중복 제거
        arr.erase(unique(arr.begin(), arr.end()), arr.end());

        // 정렬된 문자열 출력
        for (int i = 0; i < arr.size(); i++)
            cout << arr[i] << "\n";
        
        return 0;
    }