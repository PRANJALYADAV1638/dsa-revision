#include<iostream>
using namespace std;
#include<bits/stdc++.h>

    string removeOuterParentheses(string s) {
        stack<char> st;
        string ans="";

        for(int b=0;b<s.size();b++){
            if(s[b]=='('){
                if(!st.empty()){
                    ans.push_back(s[b]);
                }
                st.push('(');
            }
            else {
                st.pop();

                if(!st.empty()){
                    ans.push_back(s[b]);
                }
            }
        }
        return ans;
    
};
int main()
{
string s="(()())(())";
string ans="";
ans=removeOuterParentheses(s);
cout<<ans;
}