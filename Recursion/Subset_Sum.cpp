#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void solve(vector<int> &arr,int idx,vector<int> &ans,int sum){
    if(idx==arr.size()){
        ans.push_back(sum);
        return;
    }
    solve(arr,idx+1,ans,sum+arr[idx]);
        solve(arr,idx+1,ans,sum);

}
int main(){
vector<int> arr={3,1,2};
vector<int > ans;
solve(arr,0,ans,0);
sort(ans.begin(),ans.end());
for(int final: ans){
    cout<<final<<endl;
}
}