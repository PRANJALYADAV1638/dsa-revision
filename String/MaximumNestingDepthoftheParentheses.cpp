#include<bits/stdc++.h>
using namespace std;
int maxDepth(string s) {
        int ans=0;
int count=0;
        stack<char> st;
        for(char c: s){
            if(c=='('){
                st.push(c);
                count++;
                ans=max(ans,count);
                
            }
            else if(c==')'&&!st.empty()){
                st.pop();
                count--;
            }
        }
        return ans;
    }
int main(){
string s= "(1+(2*3)+((8)/4))+1";
int ans=maxDepth(s);
cout<<ans;
}