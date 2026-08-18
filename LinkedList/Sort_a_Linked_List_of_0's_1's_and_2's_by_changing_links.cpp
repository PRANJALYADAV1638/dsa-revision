#include <iostream>
using namespace std;

class ListNode {
public:
    int data;
    ListNode* next;

    ListNode(int val) {
        data = val;
        next = nullptr;
    }
};

ListNode* solve(ListNode* head) {
    if (head == nullptr || head->next == nullptr)
        return head;

    ListNode zeroDummy(-1), oneDummy(-1), twoDummy(-1);

    ListNode* zero = &zeroDummy;
    ListNode* one = &oneDummy;
    ListNode* two = &twoDummy;

    ListNode* temp = head;

    while (temp) {
        if (temp->data == 0) {
            zero->next = temp;
            zero = zero->next;
        }
        else if (temp->data == 1) {
            one->next = temp;
            one = one->next;
        }
        else {
            two->next = temp;
            two = two->next;
        }

        temp = temp->next;
    }

    zero->next = (oneDummy.next) ? oneDummy.next : twoDummy.next;
    one->next = twoDummy.next;
    two->next = nullptr;

    return zeroDummy.next;
}

void printList(ListNode* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(0);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(1);
    head->next->next->next->next = new ListNode(2);
    head->next->next->next->next->next = new ListNode(0);
    head->next->next->next->next->next->next = new ListNode(1);

    cout << "Original List: ";
    printList(head);

    head = solve(head);

    cout << "Sorted List: ";
    printList(head);

    return 0;
}