#include<iostream>
#include<bits/stdc++.h>
using namespace std;

string solve(string s){

    stack<string> st;

    for(int b=0; b<s.length(); b++){

        if(s[b]>='a' && s[b]<='z'){
            st.push(string(1, s[b]));
        }

        else{
            string op2 = st.top();
            st.pop();

            string op1 = st.top();
            st.pop();

            string ans = s[b] + op1 + op2;

            st.push(ans);
        }
    }

    return st.top();
}

int main(){

    string s = "abc*+d-";

    string ans = solve(s);

    cout << ans;

    return 0;
}