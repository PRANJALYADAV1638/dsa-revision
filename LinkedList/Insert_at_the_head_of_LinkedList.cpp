#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    Node* next;
    
    int val;
    Node(int data1,Node* next1){
        val=data1;
        next=next1;
    }
    Node(int data1) {
        val = data1;
        next = nullptr;
    }
};
void insert(int data, Node* &head){
Node* newnode=new Node(data);
Node* prev=head;
newnode->next=prev;
head=newnode;

}
void print(Node* head){
    Node* temp=head;
    while(temp){
        cout<<temp->val;
        temp=temp->next;
    }
}

int main(){
    Node* head=new Node(2);
    head->next=new Node(3);
    print(head);
    cout<<endl;
    int k;
    cin>>k;
    insert(k , head);
    print(head);
}