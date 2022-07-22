#include <iostream>
#include <cstring>
using namespace std;

class CNode {
    // character들을 연결 리스트로 만들기 위한 노드 클래스
    public:
        char c;
        CNode* prev;
        CNode* next;
    
    public:
        CNode()
            : c('0'), prev(nullptr), next(nullptr) {}

        CNode(char _c, CNode* _prev, CNode* _next)
            : c(_c), prev(_prev), next(_next) {}
};

class LinkedList {
    private:
        int size;
        CNode* dummy_head;
        CNode* dummy_tail;
        CNode* cursorNode;
    
    public:
        LinkedList() {
            size = 0;
            dummy_head = new CNode();
            dummy_tail = new CNode();
            dummy_head->next = dummy_tail;
            dummy_tail->prev = dummy_head;
            cursorNode = dummy_tail;
        }

        void AddFirst(char c) {
            CNode newNode(c, dummy_head, dummy_head->next);
            newNode.next->prev = &newNode;
            size++;
        }

        void AddLast(char c) {
            CNode* newNode = new CNode(c, dummy_tail->prev, dummy_tail);
            newNode->prev->next = newNode;
            dummy_tail->prev = newNode;
            size++;
        }

        void RemoveCursorLeft() {
            if (cursorNode->prev == dummy_head) return;
            CNode* removeNode = cursorNode->prev;
            removeNode->prev->next = cursorNode;
            cursorNode->prev = removeNode->prev;
            free(removeNode);
            size--;
        }

        void PushCursorLeft(char c) {
            CNode* newNode = new CNode(c, cursorNode->prev, cursorNode);
            cursorNode->prev->next = newNode;
            cursorNode->prev = newNode;
            size++;
        }

        void MoveCursorLeft() {
            if (cursorNode->prev == dummy_head) return;
            cursorNode = cursorNode->prev;
        }

        void MoveCursorRight() {
            if (cursorNode == dummy_tail) return;
            cursorNode = cursorNode->next;
        }

        void ShowData() const {
            CNode* ptr = dummy_head->next;
            while (ptr != dummy_tail) {
                cout << ptr->c;
                ptr = ptr->next;
            }
        }
};

int main(void) {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    string str;
    LinkedList list;
    int cursor;
    char instruction;
    char data;
    int T;

    cin >> str;
    cin >> T;
    
    // LinkedList에 문자열을 입력
    for (int i = 0; i < str.length(); i++) {
        list.AddLast(str[i]);
    }

    for (int i = 0; i < T; i++) {
        cin >> instruction;
        if (instruction == 'L') list.MoveCursorLeft();
        else if (instruction == 'D') list.MoveCursorRight();
        else if (instruction == 'B') list.RemoveCursorLeft();
        else {  // 'P'
            cin >> data;        // P instrunction은 data를 포함
            list.PushCursorLeft(data);
        }
    }

    list.ShowData();
    return 0;
}
