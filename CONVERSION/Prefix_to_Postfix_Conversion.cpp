#include<iostream>
#include<bits/stdc++.h>
using namespace std ;
int pr(char ch){
    if(ch=='^'){
        return 3;
    }
    if(ch=='*'||ch=='/')return 2;
    if(ch=='+'||ch=='-')return 1;
    return 0;
}
string solve(string s){
    stack<char> st;
    string ans;
    for(int b=0;b<s.length();b++){
        if(s[b]>='a'&&s[b]<='z'){
 ans.push_back(s[b]);
        }
        else{
while(!st.empty()&&pr(st.top())<=pr(s[b])){
ans.push_back(st.top());
st.pop();
}
st.push(s[b]);
        }
    }
    while(!st.empty()){
    ans.push_back(st.top());
    st.pop();
}
    return ans;
}
int main(){
    string s="*+ab-cd";
    string ans=solve(s);
    cout<<ans;
}