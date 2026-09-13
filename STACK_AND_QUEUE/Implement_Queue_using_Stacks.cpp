#include <iostream>
#include <stack>
using namespace std;

class MyQueue {
public:
    int idx;
    stack<int> s1, s2;

    MyQueue() {
        idx = -1;
    }

    void push(int x) {

        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }

        s1.push(x);

        while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
    }

    int pop() {
        int x = s1.top();
        s1.pop();
        return x;
    }

    int peek() {
        return s1.top();
    }

    bool empty() {
        return s1.empty();
    }
};

int main() {

    MyQueue q;

    q.push(10);
    q.push(20);
    q.push(30);

    cout << "Front: " << q.peek() << endl;

    cout << "Pop: " << q.pop() << endl;
    cout << "Pop: " << q.pop() << endl;

    cout << "Front: " << q.peek() << endl;

    cout << "Empty: " << (q.empty() ? "true" : "false") << endl;

    return 0;
}