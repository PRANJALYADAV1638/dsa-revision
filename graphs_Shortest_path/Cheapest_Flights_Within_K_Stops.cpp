#include<iostream>

#include<bits/stdc++.h>
using namespace std;
int solve(vector<vector<int>> arr,int  n, int src , int dst, int k ){
    vector<vector<pair<int,int>>> adj(n);
    for(int b=0;b<arr.size();b++){
        adj[arr[b][0]].push_back({arr[b][1],arr[b][2]});

    } 
    queue<pair<int,int> >q;
    q.push({src,0});
    int start=0;
    vector<int> dist(n,INT_MAX);
    dist[src]=0;
    while(!q.empty()&&start<=k){
        int size=q.size();
        vector<int> temp=dist;

        while(size--){
        int d=q.front().second;
        int node=q.front().first;
        q.pop();
      for(auto it: adj[node]){
    int cost=it.second;
    int newnode=it.first;

    if(cost+d<temp[newnode]){
        temp[newnode]=cost+d;
        q.push({newnode,cost+d});
    }
}
        }
        dist=temp;
        start++;
    }
return dist[dst]==INT_MAX?-1:dist[dst];
}
int main(){
    vector<vector<int>> arr={{0,1,100},{1,2,100},{2,0,100},{1,3,600},{2,3,200}};
    int n=4;
    int src=0;
    int dst=3;
    int k=1;
    int ans=solve(arr,n,src,dst,k);
cout<<ans;
}