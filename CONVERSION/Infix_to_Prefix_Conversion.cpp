#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
int pr(char c){
    if(c=='^'){
        return 3;
    }
    if(c=='*'||c=='/'){
        return 2;
    }
    if(c=='+'||c=='-'){
        return 1;
    }
    return 0;
}
string solve(string s){
    string ans;
    stack<char> st;
for(int b=s.length()-1;b>=0;b--){
if(s[b]>='a'&&s[b]<='z'){
    ans.push_back(s[b]);
}
  else if(s[b]=='('){

            while(!st.empty() && st.top()!=')'){
                ans.push_back(st.top());
                st.pop();
            }

            if(!st.empty()){
                st.pop();   
            }
        }
  else if(s[b]==')'){
            st.push(s[b]);
        }

else{
    while((!st.empty())&&st.top()!=')' &&(pr(st.top())>pr(s[b]))){
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
string s="((a-(b/c))*((a/k)-l))";
string ans=solve(s);
reverse(ans.begin(),ans.end());
cout<<ans;
}