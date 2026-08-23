#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
int data;
Node* prev;
Node* next;
Node(int val){
    data=val;
    next=nullptr;
    prev=nullptr;
}
};
Node* deletenode(Node* head){
    if(head==NULL)return NULL;
       if(head->next == NULL){
        delete head;
        
        return NULL;
       }
    Node* temp=head;
    Node* last =nullptr;
    while(temp->next){
        last=temp;
        temp=temp->next;
    }
last->next=NULL;
temp->prev=NULL;
delete temp;
return head;

}
void print(Node* head){
    if(head==nullptr){
        return ;
    }
    Node* head1=head;
    while(head1){
        cout<<head1->data;
        head1=head1->next;
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
   if( deletenode(head)){

       print(head);
   }
   else{
    cout<<"empty";
   }
    return 0;
}