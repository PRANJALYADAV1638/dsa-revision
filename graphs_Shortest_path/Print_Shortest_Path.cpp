#include<iostream>
#include<bits/stdc++.h>
using namespace std;
vector<int> solve (vector<vector<int>> arr,   vector<vector<pair<int, int>>> adj,int n , int m , int start, int end){
    vector<int> ans(n+1,INT_MAX);
    vector<int> parent(n+1);
    for(int b=1;b<=n;b++)parent[b]=b;
priority_queue<pair<int,int>,
vector<pair<int,int>>,
greater<pair<int,int>>> pq;

ans[start]=0;
pq.push({0,start});
while(!pq.empty()){
    int d=pq.top().first;
    int node=pq.top().second;pq.pop();
    if(d>ans[node]) continue;
    for(auto it: adj[node]){
        int adjnode=it.first;
        int weight=it.second;
if(d+weight<ans[adjnode]){
    ans[adjnode]=d+weight;
    parent[adjnode]=node;
    pq.push({ans[adjnode],adjnode});
}
    }
}
if(ans[end]==INT_MAX){
    cout<<" not possible answer ";
    return {}; 
}
int node=end;
vector<int> path;
while(parent[node]!=node){
    path.push_back(node);
    node=parent[node];
}
path.push_back(start);
reverse(path.begin(),path.end());
return path;
}
int main(){
    int n;
    int m ;
    cin>>n>>m;
    int start=1;
    int end=5;
    vector<vector<int>> arr={{1,2,2},{2,5,5},{2,3,4},{1,4,1},{4,3,3},{3,5,1}};
    vector<vector<pair<int, int>>> adj(n+1);
    for(int b=0;b<arr.size();b++){
adj[arr[b][0]].push_back({arr[b][1],arr[b][2]});
adj[arr[b][1]].push_back({arr[b][0],arr[b][2]});

}
    vector<int> ans=solve(arr,adj,n,m,start,end);
    for(int b: ans){
        cout<<b<<" ";
    }
}