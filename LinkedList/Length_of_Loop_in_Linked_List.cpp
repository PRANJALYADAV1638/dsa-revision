#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data ;
    Node* next;
    Node(int val){
        data=val;
        next=nullptr;
    }
};
int solve(Node* head){
    Node* fast=head;
    Node* slow=head;
    Node* second=nullptr;
    while(fast&&fast->next){
        slow=slow->next;
       fast=fast->next->next;
       if(slow==fast){
        slow=head;
        second=fast;
        break;
       }

    }
    if(second==nullptr)return -1;

    while(slow!=second){
        slow=slow->next;
        second=second->next;
   
    }
    head=slow;
    int count=1;
    while(head->next!=second){
count++;
head=head->next;
    }
    return count;
}
int main(){
 Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);
    Node* fourth = new Node(4);
    Node* fifth = new Node(5);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;

    
    fifth->next = second;

   int ans= solve(head);
   cout<<ans;

}