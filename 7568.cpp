#include <iostream>
using namespace std;

class Person {
    private:
        int x, y;
    public:
        Person(int _x = 0, int _y = 0)
            : x(_x), y(_y) {}
        
        bool operator>(const Person p) {
            return (x > p.x && y > p.y);
        }

        friend ostream& operator<<(ostream& os, const Person& p);
        friend istream& operator>>(istream& is, Person& p);
};

ostream& operator<< (ostream& os, const Person& p) {
    os << p.x << ", " << p.y << endl;
    return os;
}

istream& operator>> (istream& is, Person& p) {
    is >> p.x >> p.y;
    return is;
}

int main(void) {
    int x, y;
    int num_of_tc;

    cin >> num_of_tc;

    int rank[num_of_tc];        // Array to store each rank
    Person people[num_of_tc];

    for (int i = 0; i < num_of_tc; i++) {   // rank = {1, 1, 1, 1, ..., 1}
        rank[i] = 1;
    }

    for (int i = 0; i < num_of_tc; i++) {
        cin >> people[i];
    }

    for (int i = 0; i < num_of_tc; i++) {
        for (int j = 0; j < num_of_tc; j++) {
            if (people[j] > people[i]) rank[i]++; 
        }
    }

    for (int i = 0; i < num_of_tc; i++)
        cout << rank[i] << " ";
    
    return 0;
}