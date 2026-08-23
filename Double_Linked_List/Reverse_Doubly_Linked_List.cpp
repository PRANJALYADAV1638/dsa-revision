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
Node* reverse(Node* head){
    if(head==NULL)return head;
    Node* temp=head;
    while(temp->next){
        temp=temp->next;
    }
    return temp;
}
void print(Node* head){
    Node* head1=head;
    while(head1){
        cout<<head1->data;
        head1=head1->next;
    }
    
}
void printrev(Node* head){
    Node* head1=head;
    while(head){
cout<<head->data;
head=head->prev;
    }
}
int main(){
   Node* head = new Node(1);

   head->next = new Node(2);
    head->next->prev = head;

    head->next->next = new Node(3);
    head->next->next->prev = head->next;

    head->next->next->next = new Node(4);
    head->next->next->next->prev = head->next->next;
    
    print(head);
    cout<<endl;
Node* last=reverse(head);
       printrev(last);
  
    return 0;
}



/*Node* reverse(Node* head) {
    if (head == NULL || head->next == NULL)
        return head;

    Node* curr = head;
    Node* temp = NULL;

    while (curr) {
        // Swap next and prev
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;

        // Move to the next node (which is prev after swapping)
        curr = curr->prev;
    }

    // temp points to the previous node of the new head
    return temp->prev;
}*/