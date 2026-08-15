#include<bits/stdc++.h>
using namespace std;
class Node {
    public:
    int data;
    Node* next;
    Node(int val) : data(val), next(NULL) {}
};
bool find(int data1, Node* head){
    while(head){
        if(head->data==data1)return true;
        head=head->next;
    }
    return false;
}
int main(){
Node* head=new Node(1);
head->next=new Node(2);
head->next->next=new Node(3);
head->next->next->next=new Node(4);
int key;
cin>>key;

if(find(key , head)){
    cout<<"find";
}
else{
    cout<<"not find";
}
}