#include <iostream>
#include <queue>
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
    queue<int> q;


    for (int i = 0; i < T; i++) {
        cin >> instruction;
        if (instruction == "push") {
            cin >> data;
            q.push(data);
        } else if (instruction == "pop") {
            if (q.empty()) cout << "-1\n";
            else {
                cout << q.front() << "\n";
                q.pop();
            }
        } else if (instruction == "size") {
            cout << q.size() << "\n";
        } else if (instruction == "empty") {
            cout << q.empty() << "\n";
        } else if (instruction == "front") {
            if (q.empty()) cout << "-1\n";
            else {
                cout << q.front() << "\n";
            }
        } else {    // back
            if (q.empty()) cout << "-1\n";
            else {
                cout << q.back() << "\n";
            }
        }
    }
    return 0;
}