#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    int val;
node* next;
node(int data){
    val=data;
    next=NULL;
}
};
class ll{
    int size;
    node* head;
    node* tail;
    public:
    ll(){
size=-1;
tail=NULL;
head=NULL;
    }
void push(int x){
node* temp=new node(x);
if(size==-1){
    head=temp;
    tail=temp;
    size++;
    return ;
}
tail->next=temp;
tail=tail->next;
size++;
};
int pop(){
    if(size==-1){
        cout<<"EMPTY ";
        return -1;
    }
node* temp=head;
head=temp->next;
int ans=temp->val;
delete temp;
size--;
 if(size==-1){
        tail=NULL;
    }
return ans;
};
int peek(){
if(size==-1){
        cout<<"EMPTY ";
        return -1;
    }
    return head->val;
};
bool empty(){
return size==-1;
}

};
int main(){
    ll ans;
 vector<string> commands = {"LinkedListQueue", "push", "push", 
                               "peek", "pop", "isEmpty"};
 
    vector<vector<int>> inputs = {{}, {3}, {7}, {}, {}, {}};
for(auto b=0;b<commands.size();b++){
    if(commands[b]=="LinkedListQueue"){
        cout<<"NULL  ";
    }
    if(commands[b]=="push"){
        ans.push(inputs[b][0]);
        cout<<"NULL ";
    }
    if(commands[b]=="pop"){
        cout<<ans.pop()<<" ";
    }
    if(commands[b]=="peek"){
        cout<<ans.peek()<<" ";
    }
    if(commands[b]=="isEmpty"){
        if(ans.empty()){
            cout<<"empty ";
        }
        else{
            cout<<" not empty ";
        }
    }
}

}