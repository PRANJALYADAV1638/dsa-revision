#include<iostream>
#include<bits/stdc++.h>
using namespace std;
vector<int> solve(int V, vector<vector<int>> &adj){
    vector<int> indegree(V);
for(int b=0;b<V;b++){
    for(int c:adj[b]){
        indegree[c]++;
    }
}

vector<int> ans;
queue<int> q;
for(int b=0;b<V;b++){
    if(indegree[b]==0){
        q.push(b);
    }
}
while(!q.empty()){
    int node=q.front();
    q.pop();
    ans.push_back(node);
    for(int i :adj[node]){
        indegree[i]--;
        if(indegree[i]==0){
            q.push(i);
        }
    }
}
return ans;
}
int main(){
    int V = 4; 
    vector<vector<int>> adj(V); 
    adj[0].push_back(1); 
    adj[0].push_back(2); 
    adj[1].push_back(3);
     adj[2].push_back(3);
     vector<int> ans=solve(V,adj);
     for(int b: ans){
        cout<<b<<" ";
         }
}