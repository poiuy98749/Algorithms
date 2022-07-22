#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int T;
    cin >> T;

    string instruction;
    int data;
    deque<int> d;
    
    for (int i = 0; i < T; i++) {
        cin >> instruction;
        if (instruction == "push_front") {
            cin >> data;
            d.push_front(data);
        } else if (instruction == "push_back") {
            cin >> data;
            d.push_back(data);
        } else if (instruction == "pop_front") {
            if (d.empty()) cout << "-1\n";
            else {
                cout << d.front() << "\n";
                d.pop_front();
            }
        } else if (instruction == "pop_back") {
            if (d.empty()) cout << "-1\n";
            else {
                cout << d.back() << "\n";
                d.pop_back();
            }
        } else if (instruction == "size") {
            cout << d.size() << "\n";
        } else if (instruction == "empty") {
            cout << d.empty() << "\n";
        } else if (instruction == "front") {
            if (d.empty()) cout << "-1\n";
            else {
                cout << d.front() << "\n";
            }
        } else {    // back
            if (d.empty()) cout << "-1\n";
            else {
                cout << d.back() << "\n";
            }
        }
    }
    return 0;
}