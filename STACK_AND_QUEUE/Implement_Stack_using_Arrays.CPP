#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class arraystack{
    int* stackarray;
    int cap;
    int topidx;
    public:
    arraystack(int val=1000){
        cap=val;
        stackarray=new int [cap];
        topidx=-1;

    }
void push(int x){
    if(topidx>=cap-1){
        cout<<"stack overflow ";
        return ;
    }
    topidx++;
    stackarray[topidx]=x;
}
int pop(){
    if(topidx<=0){
        cout<<"empty";
        return -1;
}

return stackarray[topidx--];

};
int top(){
    if(topidx<0){
        cout<<"empty";

    return -1;
}
    else if(topidx>=cap){
        cout<<"overflow";
        return -1;
    }
    return stackarray[topidx];
}
bool isempty(){
    if(topidx==-1){
        return true;
    }
    return false;
}
};
int main(){
vector<string> que={"arraystack","push","push","top","pop","isempty"};
 vector<vector<int>> inputs = {{}, {5}, {10}, {}, {}, {}};
arraystack st;
 for(auto b=0;b<que.size();b++){
    if(que[b]=="arraystack"){
        cout<<"null";
    }
if(que[b]=="push"){
st.push(inputs[b][0]);
cout<<"null"<<"  ";
}
 if(que[b]=="pop"){
    cout<<st.pop()<<"  ";
 }   
 if(que[b]=="top"){
    cout<<st.top()<<"  ";
 }
 if(que[b]=="isempty"){
if(st.isempty()){
    cout<<"true"<<"  ";
 }
 else{
    cout<<"false"<<"  ";
 }
 }
}
}