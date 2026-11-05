#include<bits/stdc++.h>
#include<iostream>
using namespace std;
vector<int> solve(vector<vector<int>> &arr,int n , int m ){
    vector<int> ans(n,-1);
vector<vector<int>> adj(n);
for(int b=0;b<m;b++){
    adj[arr[b][0]].push_back(arr[b][1]);
    adj[arr[b][1]].push_back(arr[b][0]);
}
queue<int> q;
q.push(0);
ans[0]=0;
while(!q.empty()){
    int node=q.front();
    q.pop();
    for(int it: adj[node]){
        if(ans[it]==-1){
            ans[it]=ans[node]+1;
            q.push(it);
        }
    }
}

    return ans;
}
int main(){
vector<vector<int>> arr={{0,1},{0,3},{3,4},{4,5},{5,6,},{1,2},{2,6},{6,7},{7,8},{6,8}};
int n ;
int m ;
cin>>n>>m;
vector<int> ans=solve(arr,n,m);
for(int b: ans){
    cout<<b<<" ";
}
}