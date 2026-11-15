#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int solve(vector<vector<int>> &arr,int n , int k ){
    vector<vector<pair<int , int>>> adj(n+1);
    for(int b=0;b<arr.size();b++){
        adj[arr[b][0]].push_back({arr[b][1],arr[b][2]});
    }

    priority_queue<
                pair<long long,int>,
                vector<pair<long long,int>>,
                greater<pair<long long,int>>
            > q;

            vector<int> dist(n+1,INT_MAX);
            dist[k]=0;
            q.push({0,k});
            while(!q.empty()){
                int d=q.top().first;
                int node=q.top().second;
                q.pop();
                for(auto it : adj[node]){
                    int cost=it.second;
                    int newnode=it.first;
                    int newdist=d+cost;
                    if(newdist<dist[newnode]){
                        dist[newnode]=newdist;
                        q.push({newdist,newnode});
                    }
                }
            }
            int max=0;
            for(int b=1;b<=n;b++){
if(dist[b]==INT_MAX)return -1;
if(dist[b]>max){
    max=dist[b];
}
            }
            return max;
}
int main(){
    vector<vector<int>> arr={{2,1,1},{2,3,1},{3,4,1}};
    int n =4;
    int k =2;
    int ans=solve(arr,n,k);
    cout<<ans;
    
}