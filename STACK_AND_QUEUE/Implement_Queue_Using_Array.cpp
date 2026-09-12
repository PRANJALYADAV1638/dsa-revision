#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class arrayqueue{
int cap;
int* queuearray;
int stt;
int end;

public:
arrayqueue(int size=1000){
    cap=size;
    stt=0;
    end=-1;
    queuearray=new int[cap];
}
void push(int x){
    if(end==cap-1){
        cout<<"overflow"<<" ";
        return ;
    }
end++;
queuearray[end]=x;
}
int pop(){
 if(stt > end){
        cout<<"underflow";
        return -1;
    }
return queuearray[stt++];
}
int top(){
if(stt>end){
    cout<<"underflow";
    return -1;
}

return queuearray[stt];
}
bool isempty(){
    return stt > end;
}
};
int main(){
    vector<string> ques={"arrayqueue","push","push","top","pop","isempty"};
    vector<vector<int>> inputs={{},{5},{10},{},{},{}};
arrayqueue queue;
    for(auto b=0;b<ques.size();b++){
        if(ques[b]=="arrayqueue"){
            cout<<"NULL"<<"  ";
        }
        if(ques[b]=="push"){
            queue.push(inputs[b][0]);
            cout<<"NULL  ";
        }
        if(ques[b]=="pop"){
            cout<<queue.pop()<<"  ";
        }
        if(ques[b]=="top"){
            cout<<queue.top()<<"  ";
        }
        if(ques[b]=="isempty"){
            if(queue.isempty()){
                cout<<"true  ";
            }
            else{
                cout<<"false  ";
            }
        }
    }
    return 0;
}