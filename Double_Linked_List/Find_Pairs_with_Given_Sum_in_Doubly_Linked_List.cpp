#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int val) {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};

vector<pair<int, int>> findPairs(Node* head, int target) {

    vector<pair<int, int>> ans;

    if (head == nullptr)
        return ans;

    Node* left = head;
    Node* right = head;

    // Move to the last node
    while (right->next)
        right = right->next;

    while (left != right && left->prev != right) {

        int sum = left->data + right->data;

        if (sum == target) {
            ans.push_back({left->data, right->data});
            left = left->next;
            right = right->prev;
        }
        else if (sum < target) {
            left = left->next;
        }
        else {
            right = right->prev;
        }
    }

    return ans;
}

int main() {

    Node* head = new Node(1);

    head->next = new Node(2);
    head->next->prev = head;

    head->next->next = new Node(3);
    head->next->next->prev = head->next;

    head->next->next->next = new Node(4);
    head->next->next->next->prev = head->next->next;

    head->next->next->next->next = new Node(5);
    head->next->next->next->next->prev = head->next->next->next;

    head->next->next->next->next->next = new Node(6);
    head->next->next->next->next->next->prev =
        head->next->next->next->next;

    int target;
    cin >> target;

    vector<pair<int, int>> ans = findPairs(head, target);

    for (auto p : ans) {
        cout << "(" << p.first << "," << p.second << ") ";
    }

    return 0;
}