#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) {
        val = x;
        next = nullptr;
    }
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;

        ListNode* prev = nullptr;

        while (head) {
            ListNode* right = head->next;
            head->next = prev;
            prev = head;
            head = right;
        }

        return prev;
    }
};

void printList(ListNode* head) {
    while (head) {
        cout << head->val << "->";
        head = head->next;
    }
    cout << endl;
}

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    cout << "Original List: ";
    printList(head);

    Solution obj;
    head = obj.reverseList(head);

    cout << "Reversed List: ";
    printList(head);

    return 0;
}