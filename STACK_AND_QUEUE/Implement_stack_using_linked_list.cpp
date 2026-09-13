#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct Node {
    int val;
    Node *next;
    Node(int d) {
        val = d;
        next = NULL;
    }
};

class ll{
int size;
Node* head;
public:
ll(){
    size=-1;
    head=nullptr;
}
void push(int x){
    Node* element=new Node(x);
    element->next=head;
    head=element;
    size++;
};
int pop(){
    if(size==-1){
        cout<<"empty";
    return -1;
}
int val=head->val;
Node* temp=head;
head=temp->next;
delete temp;
size--;
return val;
}
int top(){
    if(size==-1){
        cout<<"empty ";
        return -1;
    }
    return head->val;
}
bool isEmpty(){
    return size==0;
}
};
int main(){
ll ans;
   vector<string> commands = {"LinkedListStack", "push", "push", 
                               "pop", "top", "isEmpty"};
                                  vector<vector<int>> inputs = {{}, {3}, {7}, {}, {}, {}};
for(auto b=0;b<commands.size();b++){
if(commands[b]=="LinkedListStack"){
cout<<"NULL"<<"  ";
}
if(commands[b]=="push"){
ans.push(inputs[b][0]);
cout<<"NULL  ";
}
if(commands[b]=="pop"){
cout<<ans.pop()<<"  ";
}
if(commands[b]=="top"){
 cout<<ans.top()<<"  ";
}
if(commands[b]=="isEmpty"){
if(ans.isEmpty()){
    cout<<" not EMPTY ";
}
else{
    cout<<" EMPTY ";
}
}
}                               

}