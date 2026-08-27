#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void solve(int open ,int close,int n , string curr , vector<string> &ans){
    if(curr.length()==2*n){
   ans.push_back(curr);
   return;
    }
    if(open<n){
        solve(open+1,close,n,curr+"(",ans);
    }
    if(close<open){
        solve(open,close+1,n,curr+")",ans);
    }
}
int main(){
    int n ;
    cin>> n;
    vector<string> ans;
    string curr="";
    solve(0,0,n,curr,ans);
    for (string final : ans){
        cout<<final<<endl;
    }
}