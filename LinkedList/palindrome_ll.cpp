#include <bits/stdc++.h>
using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;

    ListNode(int x) {
        val = x;
        next = nullptr;
    }
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (head == nullptr) return true;

        stack<int> st;
        ListNode* temp = head;

        int count = 0;
        while (temp) {
            count++;
            temp = temp->next;
        }

        int check = 0;

        if (count % 2 == 0) {
            while (check < count / 2) {
                st.push(head->val);
                head = head->next;
                check++;
            }
        } else {
            while (check < count / 2) {
                st.push(head->val);
                head = head->next;
                check++;
            }
            head = head->next;
        }

        while (head) {
            if (head->val != st.top())
                return false;
            st.pop();
            head = head->next;
        }

        return true;
    }
};

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(2);
    head->next->next->next->next = new ListNode(1);

    Solution obj;

    if (obj.isPalindrome(head))
        cout << "Palindrome";
    else
        cout << "Not Palindrome";

    return 0;
}