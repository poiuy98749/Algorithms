#include <iostream>
using namespace std;

int main(void) {
    int A, B, V;
    cin >> A >> B >> V;
    int count = 0;
    int current_height = 0;
    
    // First go up to V - A
    count = (V - A) / (A - B);
    current_height = (A - B) * count;

    while (true) {
        count++;
        current_height += A;
        if (current_height >= V) break;
        current_height -= B;
    }

    cout << count << endl;
}