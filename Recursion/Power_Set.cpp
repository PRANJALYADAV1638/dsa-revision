#include<bits/stdc++.h>
using namespace std;
void solve(string s , int idx,string curr,vector<string> &ans){
    if(idx==s.length()){
        ans.push_back(curr);
        return ;
    }

    solve(s,idx+1,curr+s[idx],ans);
    solve(s,idx+1,curr,ans);
}
int main(){
    string s;
    cin>>s;
    vector<string> ans;
    string curr="";
    solve(s,0,curr,ans);
    for(string final : ans){
        cout<<final<<endl;
    }
}