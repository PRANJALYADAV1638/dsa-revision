#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class node{
public:
node* next;
int data;
node(int val){
    data=val;
    next=NULL;
}
};
class solution{
    public:
    node* solve(node* head){
node* slow=head;
node* fast=head;
while(fast&&fast->next){
    slow=slow->next;
    fast=fast->next->next;
}
return slow;
    }
};
int main(){
node* head=new node(1);
head->next=new node(2);
head->next->next=new node(3);
head->next->next->next=new node(4);
head->next->next->next->next=new node(5);
solution sol;
node* ans;
ans=sol.solve(head);
cout<<ans->data;
}