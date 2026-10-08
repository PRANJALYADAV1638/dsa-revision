#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int solve(string s){
    set<char> st;
    int ans=0;
    int left=0;
    int right=0;
    while(right<s.length()){
        if(st.find(s[right])==st.end()){
        st.insert(s[right]);
        right++;

        }
        else{
            st.erase(s[left]);
            left++;
        }
        ans=max(ans,right-left);
    }
    return ans;
}
int main(){
    string s="pwwkewf";
    int ans=solve(s);
    cout<<ans;
}