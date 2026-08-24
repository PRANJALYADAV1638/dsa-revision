#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node* prev;
    Node(int val){
        data=val;
        next=nullptr;
        prev=nullptr;
    }
};
Node* remove(Node* head,int target){
    if(head==nullptr)return nullptr;
        while (head && head->data == target) {
        Node* temp = head;
        head = head->next;
        if (head)
            head->prev = nullptr;
        delete temp;
    }
if(head == nullptr)
    return nullptr;
Node* curr=head;
Node* left=nullptr;
Node* right=curr->next;
while(curr){
    

    if(curr->data==target){
        left->next=curr->next;
        if(curr->next){
        curr->next->prev=left;
        }
        Node* dlt=curr;
        delete dlt;
     curr = right;
if (right)
    right = right->next;
    }
    else{
        left=curr;
        curr=right;
  if (right)
                right = right->next;
        }    }

return head;
}
void print(Node* head){
    Node* temp=head;
    while(temp){
        cout<<temp->data;
        temp=temp->next;
    }
}
int main(){
    Node* head = new Node(1);

head->next = new Node(2);
head->next->prev = head;

head->next->next = new Node(3);
head->next->next->prev = head->next;

head->next->next->next = new Node(2);
head->next->next->next->prev = head->next->next;

head->next->next->next->next = new Node(4);
head->next->next->next->next->prev = head->next->next->next;

head->next->next->next->next->next = new Node(5);
head->next->next->next->next->next->prev =
    head->next->next->next->next;

head->next->next->next->next->next->next = new Node(2);
head->next->next->next->next->next->next->prev =
    head->next->next->next->next->next;
    int target;
    cin>> target;
    print(head);
    cout<<endl;
 head=   remove(head,target);
    print(head);
}





/*Node* remove(Node* head, int target) {
    if (head == nullptr)
        return nullptr;

    Node* curr = head;

    while (curr) {
        if (curr->data == target) {

            // If deleting the head
            if (curr == head) {
                head = head->next;
                if (head)
                    head->prev = nullptr;
            }
            else {
                curr->prev->next = curr->next;
                if (curr->next)
                    curr->next->prev = curr->prev;
            }

            Node* temp = curr;
            curr = curr->next;
            delete temp;
        }
        else {
            curr = curr->next;
        }
    }

    return head;
}*/