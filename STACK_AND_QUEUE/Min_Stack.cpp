#include <iostream>
#include <stack>
using namespace std;

class MinStack {
public:
    stack<int> st;
    stack<int> minSt;

    MinStack() {
    }

    void push(int value) {

        st.push(value);

        if (minSt.empty() || value <= minSt.top()) {
            minSt.push(value);
        }
    }

    void pop() {

        if (st.empty()) {
            return;
        }

        if (st.top() == minSt.top()) {
            minSt.pop();
        }

        st.pop();
    }

    int top() {

        if (st.empty()) {
            return -1;
        }

        return st.top();
    }

    int getMin() {

        if (minSt.empty()) {
            return -1;
        }

        return minSt.top();
    }
};

int main() {

    MinStack st;

    st.push(5);
    st.push(3);
    st.push(7);
    st.push(2);
    st.push(4);

    cout << "Top: " << st.top() << endl;
    cout << "Minimum: " << st.getMin() << endl;

    st.pop();

    cout << "After pop:" << endl;
    cout << "Top: " << st.top() << endl;
    cout << "Minimum: " << st.getMin() << endl;

    st.pop();

    cout << "After another pop:" << endl;
    cout << "Top: " << st.top() << endl;
    cout << "Minimum: " << st.getMin() << endl;

    return 0;
}