#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int pr(char ch){
    if(ch=='^'){
        return 3;
    }
    if(ch=='/'||ch=='*'){
        return 2;
    }
    if(ch=='+'||ch=='-'){
        return 1;
    }
    return 0;
}

string solve(string s){
    string ans;
    stack<string> st;

    for(int b=s.length()-1;b>=0;b--){

        if(s[b]>='a'&&s[b]<='z'){
            st.push(string(1,s[b]));   
        }

        else{
            string op1=st.top();
            st.pop();

            string op2=st.top();
            st.pop();

            ans="("+op1+s[b]+op2+")";

            st.push(ans);
        }
    }

    return st.top();
}

int main(){
    string s="^a*bc";
    string ans=solve(s);
    cout<<ans;
}