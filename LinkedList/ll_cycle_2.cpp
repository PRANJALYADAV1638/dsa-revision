#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    int data ;
    node* next;
    node(int val){
        data=val;
        next=nullptr;
    }
};
node* cycle(node* head){
node* slow=head;
node* fast=head;
node* num=nullptr;
while(fast&&fast->next){
    slow=slow->next;
    fast=fast->next->next;
    if(fast==slow){
        slow=head;
   num=fast;
   break;
    }
}
if(num==nullptr)return nullptr;
while(slow!=num){
slow=slow->next;
num=num->next;

}
return slow;
}
int main(){
   node* head = new node(1);
    node* second = new node(2);
    node* third = new node(3);
    node* fourth = new node(4);
    node* fifth = new node(5);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;

   fifth->next = third;  
   head=cycle(head);
   cout<<head->data;

}