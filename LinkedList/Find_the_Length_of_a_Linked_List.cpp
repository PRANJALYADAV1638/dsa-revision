#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Node {
public:
    int data;
    Node* next;

    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};
int count(Node* head){
    int ans=0;
    while(head){
        head=head->next;
        ans++;
    }
    return ans;
}
int main(){
    Node* head= new Node(1);
    head->next=new Node(2);
    head->next->next=new Node(3);
   // head->next->next->next=new Node(4);
    int ans=count(head);
    cout<<ans;
}