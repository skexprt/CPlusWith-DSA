#include <iostream>
#include <queue>
using namespace std;

class Stack {
    queue<int> q1;
    queue<int> q2;

public:
    void push(int data) {
        // Move all elements from q1 to q2
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }

        // Push the new data into q1
        q1.push(data);

        // Move everything back to q1 from q2
        while (!q2.empty()) {
            q1.push(q2.front());
            q2.pop();
        }
    }

    void pop() {
        if (!q1.empty())
            q1.pop();
    }

    int top() {
        if (!q1.empty())
            return q1.front();
        return -1; // or throw exception
    }

    bool empty() {
        return q1.empty();
    }
};

int main() {
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);

    while (!s.empty()) {
        cout << s.top() << endl; // prints top element
        s.pop(); // removes top element
    }

    return 0;
}
