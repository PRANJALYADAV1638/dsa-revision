#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* curr = head;

        unordered_map<Node*, Node*> mp;

        while (curr) {
            mp[curr] = new Node(curr->val);
            curr = curr->next;
        }

        curr = head;

        while (curr) {
            mp[curr]->next = mp[curr->next];
            mp[curr]->random = mp[curr->random];

            curr = curr->next;
        }

        return mp[head];
    }
};

void printList(Node* head) {
    Node* curr = head;

    while (curr) {
        cout << "Node: " << curr->val;

        if (curr->random)
            cout << ", Random: " << curr->random->val;
        else
            cout << ", Random: NULL";

        cout << endl;

        curr = curr->next;
    }
}

int main() {


    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);

    node1->next = node2;
    node2->next = node3;
    node3->next = NULL;

    
    node1->random = node3;
    node2->random = node1;
    node3->random = node2;

    Node* head = node1;

    cout << "Original List:" << endl;
    printList(head);

    
    Solution obj;
    Node* copiedHead = obj.copyRandomList(head);

    cout << "\nCopied List:" << endl;
    printList(copiedHead);

    return 0;
}
