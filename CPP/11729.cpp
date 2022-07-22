#include <iostream>
#include <string>
using namespace std;

void Hanoi(int num, int from, int by, int to, string &buffer, int &count) {
    if (num == 1) {
        buffer += (to_string(from) + ' ' + to_string(to) + '\n');
        count++;
        return;
    }

    Hanoi(num - 1, from, to, by, buffer, count);
    buffer += (to_string(from) + ' ' + to_string(to) + '\n');
    count++;

    Hanoi(num - 1, by, from, to, buffer, count);
}

int main(void) {
    int num;
    int count = 0;
    string buffer = "";

    cin >> num;
    Hanoi(num, 1, 2, 3, buffer, count);

    cout << count << "\n";
    cout << buffer;
    return 0;
}
