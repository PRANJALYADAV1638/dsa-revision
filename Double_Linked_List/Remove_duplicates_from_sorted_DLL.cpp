#include<iostream>
using namespace std;
#include<bits/stdc++.h>
class Node{
    public:
    int data;
    Node* next;
    Node* prev;
    Node(int val){
        next=nullptr;
        prev=nullptr;
        data=val;
    }
};
void print(Node* head){
    Node* temp=head;
    while(temp){
        cout<<temp->data;
        temp=temp->next;
    }
}
Node* remove(Node* head){
    if(head==nullptr)return head;
if(head->next==nullptr)return head;
Node* agla=head->next;
Node* curr=head;
while(agla){
    if(agla->data==curr->data){
    curr->next=agla->next;

            if (agla->next)
                agla->next->prev = curr;
                  Node* temp = agla;
            agla = curr->next;
            delete temp;

    }
    else{
        curr=agla;
            agla=agla->next;
        
    }
}
return head;
}
int main(){
Node* head = new Node(1);

head->next = new Node(1);
head->next->prev = head;

head->next->next = new Node(1);
head->next->next->prev = head->next;

head->next->next->next = new Node(2);
head->next->next->next->prev = head->next->next;

head->next->next->next->next = new Node(2);
head->next->next->next->next->prev = head->next->next->next;

head->next->next->next->next->next = new Node(2);
head->next->next->next->next->next->prev =
    head->next->next->next->next;

head->next->next->next->next->next->next = new Node(3);
head->next->next->next->next->next->next->prev =
    head->next->next->next->next->next;

head->next->next->next->next->next->next->next = new Node(3);
head->next->next->next->next->next->next->next->prev =
    head->next->next->next->next->next->next;

head->next->next->next->next->next->next->next->next = new Node(3);
head->next->next->next->next->next->next->next->next->prev =
    head->next->next->next->next->next->next->next;

head->next->next->next->next->next->next->next->next->next = new Node(4);
head->next->next->next->next->next->next->next->next->next->prev =
    head->next->next->next->next->next->next->next->next;


    print(head);
    cout<<endl;
  head=remove(head);
    print(head);
}