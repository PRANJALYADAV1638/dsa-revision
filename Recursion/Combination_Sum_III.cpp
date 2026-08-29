#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void solve(int k,int idx ,int target,vector<vector<int>> &ans , vector<int> &com,int i ){
if(target==0&&idx==k){
    ans.push_back(com);
    return ;
}
if(target<0||idx==k)return ;
for(int b=i;b<=9;b++){
           if(b>target)break;

    com.push_back(b);
    solve(k,idx+1,target-b,ans,com,b+1);
    com.pop_back();
}
}
int main(){
    int k ;
    cin>>k;
    int target;
    cin>>target;
    vector<vector<int>> ans;
    vector<int> com;
solve(k,0,target,ans,com,1);

   for (auto &final : ans) {
    for (int x : final)
        cout << x << " ";
    cout << "\n";
}
}