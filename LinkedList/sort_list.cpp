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
    ListNode* conqour(ListNode* head, ListNode* stt, ListNode* end) {
        ListNode* left1 = stt;
        ListNode* left2 = end;

        if (!left1) return left2;
        if (!left2) return left1;

        ListNode* ans = nullptr;
        ListNode* tail = nullptr;

        if (left1->val < left2->val) {
            ans = tail = left1;
            left1 = left1->next;
        } else {
            ans = tail = left2;
            left2 = left2->next;
        }

        while (left1 && left2) {
            if (left1->val < left2->val) {
                tail->next = left1;
                left1 = left1->next;
            } else {
                tail->next = left2;
                left2 = left2->next;
            }
            tail = tail->next;
        }

        if (left1)
            tail->next = left1;
        else
            tail->next = left2;

        return ans;
    }

    ListNode* divide(ListNode* head, ListNode* stt, ListNode* end) {
        if (head == nullptr || head->next == nullptr)
            return head;

        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* left2 = slow->next;
        slow->next = nullptr;

        ListNode* left = divide(head, head, slow);
        ListNode* right = divide(left2, left2, end);

        return conqour(head, left, right);
    }

    ListNode* sortList(ListNode* head) {
        if (!head)
            return nullptr;

        ListNode* temp = head;
        while (temp)
            temp = temp->next;

        return divide(head, head, temp);
    }
};

void printList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    ListNode* head = new ListNode(4);
    head->next = new ListNode(2);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(5);

    cout << "Original List: ";
    printList(head);

    Solution obj;
    head = obj.sortList(head);

    cout << "Sorted List: ";
    printList(head);

    return 0;
}