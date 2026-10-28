#include<iostream>
#include<bits/stdc++.h>
using namespace std;
vector<int> solve(vector<vector<int>> &arr){
    int n =arr.size();
    vector<vector<int>> adj(n);
    vector<int> indegree(n,0);
    vector<int> ans;
    for(int b=0;b<n;b++){
for(int node: arr[b]){
    adj[node].push_back(b);
    indegree[b]++;
}
    }

    queue<int> q;
    for(int b=0;b<n;b++){
        if(indegree[b]==0){
            q.push(b);
        }
    }
    while(!q.empty()){
        int node= q.front();
        q.pop();
        ans.push_back(node);
        for(int b:adj[node]){
        
            indegree[b]--; 
        if(indegree[b]==0){
            q.push(b);
        }
        }

    }
    sort(ans.begin(),ans.end());
    return ans;
}
int main(){
    vector<vector<int>> arr={{1,2},{2,3},{5},{0},{5},{},{}};
    vector<int> ans=solve(arr);
    for(int b: ans){
        cout<<b<<" ";
    }
}