#include <iostream>
#include <cstring>
using namespace std;

class Stack {
    private:
        int max;
        int ptr;
        int* stack;

        bool IsFull();
    
    public:
        Stack(int size);
        bool Push(int x);
        int Pop();
        int Size();
        bool IsEmpty();
        int Top();
};

Stack::Stack(int size) {
    max = size;
    ptr = 0;
    stack = new int[size];
}

bool Stack::Push(int x) {
    if (IsFull()) return false;
    else {
        stack[ptr++] = x;
        return true;
    }
}

int Stack::Pop() {
    if (IsEmpty()) return -1;
    else {
        return stack[--ptr];
    }
}

int Stack::Size() {
    return ptr;
}

bool Stack::IsEmpty() {
    return (ptr == 0);
}

int Stack::Top() {
    if (IsEmpty()) return -1;
    else {
        return stack[ptr - 1];
    }
}

bool Stack::IsFull() {
    return (ptr >= max);
}

int main(void) {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    int T;
    cin >> T;
    string instruction;
    int value;

    Stack stack(T);

    for (int i = 0; i < T; i++) {
        cin >> instruction;
        
        if (instruction == "push") {
            cin >> value;
            stack.Push(value);
        } else if (instruction == "pop") {
            cout << stack.Pop() << "\n";
        } else if (instruction == "size") {
            cout << stack.Size() << "\n";
        } else if (instruction == "empty") {
            cout << stack.IsEmpty() << "\n";
        } else {
            cout << stack.Top() << "\n";
        }
    }

    return 0;
}