#include<iostream>
#include<bits//stdc++.h>
using namespace std;
int solve(int n , vector<vector<int>> arr){
    vector<vector<pair<int, int >>> adj(n);
    for(int b=0;b<arr.size();b++){
        adj[arr[b][0]].push_back({arr[b][1],arr[b][2]});
                adj[arr[b][1]].push_back({arr[b][0],arr[b][2]});

    }
    vector<int> ways(n);
vector<long long > dist(n,LLONG_MAX);
dist[0]=0;
ways[0]=1;
int mod=1e9+7;
        priority_queue<
            pair<long long,int>,
            vector<pair<long long,int>>,
            greater<pair<long long,int>>
        > q;

        q.push({0,0});
        while(!q.empty()){
            long long d=q.top().first;
            int node=q.top().second;
            q.pop();
            if(d > dist[node]) continue;
            for(auto it: adj[node]){
long long cost =it.second;
int newnode=it.first;
     long long newdist=d+cost;
     if(newdist<dist[newnode]){
        dist[newnode]=newdist;
        ways[newnode]=ways[node];
        q.push({newdist,newnode});
     }
     else if(newdist==dist[newnode]){
        ways[newnode]=(ways[node]+ways[newnode])%mod;
     }
            }
        }
return ways[n-1];
    }
int main(){
    vector<vector<int>> arr={{0,6,7},{0,1,2},{1,2,3},{1,3,3},{6,3,3},{3,5,1},{6,5,1},{2,5,1},{0,4,5},{4,6,2}};
   int n =7;
    int ans=solve(n,arr);
    cout<<ans;
}