#include<iostream>
#include<bits/stdc++.h>
using namespace std;
vector<int> solve(vector<int> arr){
    stack<int> st;
    vector<int> ans(arr.size());
    for(int b=arr.size()-1;b>=0;b--){
        while(!st.empty()&&st.top()>arr[b]){
            st.pop();
        }
        if(st.empty()){
            ans[b]=-1;
        }
        else{
            ans[b]=st.top();
        }
        st.push(arr[b]);
    }
    return ans;
}
int main(){
    vector<int> arr={4,8,5,2,25};
    vector<int> ans;
    ans=solve(arr);
    for(int c: ans){
        cout<<c<<" ";
        }
}