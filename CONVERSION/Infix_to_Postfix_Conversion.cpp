#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int priority(char ch){
    if (ch == '^')
        return 3;
    else if (ch == '*' || ch == '/')
        return 2;
    else if (ch == '+' || ch == '-')
        return 1;
    else
        return 0;
};
string solve(string s){
    string ans="";
    stack<char> st;
   
    for(int b=0;b<s.length();b++){
if(s[b]>='a'&&s[b]<='z'){
    ans.push_back(s[b]);
}
else{
    
    while(!st.empty()&&(priority(s[b])<=priority(st.top()))){
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
    string s="a+b*c";
    string ans=solve(s);
    cout<<ans;
}