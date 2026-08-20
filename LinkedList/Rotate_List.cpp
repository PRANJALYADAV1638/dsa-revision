#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || k == 0) return head;

        ListNode* temp = head;
        ListNode* number = head;
        int count = 0;

        while (number) {
            number = number->next;
            count++;
        }

        k = k % count;

        if (k == 0) return head;

        for (int b = 0; b < k; b++) {
            temp = temp->next;
        }

        ListNode* head2 = head;

        while (temp->next) {
            temp = temp->next;
            head2 = head2->next;
        }

        ListNode* newHead = head2->next;

        temp->next = head;
        head2->next = nullptr;

        return newHead;
    }
};

// Print linked list
void printList(ListNode* head) {
    while (head) {
        cout << head->val;

        if (head->next)
            cout << " -> ";

        head = head->next;
    }
    cout << endl;
}

int main() {
    // Create:
    // 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    int k = 2;

    cout << "Original list: ";
    printList(head);

    Solution obj;
    head = obj.rotateRight(head, k);

    cout << "After rotating right by " << k << ": ";
    printList(head);

    return 0;
}
