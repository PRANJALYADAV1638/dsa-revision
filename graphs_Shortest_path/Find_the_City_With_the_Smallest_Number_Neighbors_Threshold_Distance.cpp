

/*
 hrr city k liya algorithm lagai 
*/


#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int solve(vector<vector<int>> &arr,int n , int threshold){
    vector<vector<pair<int, int >> >adj(n);
    for(int b=0;b<arr.size();b++){
        adj[arr[b][0]].push_back({arr[b][1],arr[b][2]});

                adj[arr[b][1]].push_back({arr[b][0],arr[b][2]});

    }
    vector<int> ans(n);
    for(int src=0;src<n;src++){
        vector<int> dist(n,INT_MAX);
        
            priority_queue<
                pair<long long,int>,
                vector<pair<long long,int>>,
                greater<pair<long long,int>>
            > q;

            q.push({0,src});
            dist[src]=0;
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
            for(int b=0;b<n;b++){
                if(b!=src&&dist[b]<=threshold){
                    ans[src]++;
                }

            }
        }
            int final=0;
            for(int b=0;b<n;b++){
if(ans[b]<=ans[final]){
    final=b;
}
            }

return final;
}
int main(){
    vector<vector<int>> arr={{0,1,3},{1,2,1},{1,3,4},{2,3,1}};
    int threshold=4;
    int n =4;
    int ans= solve( arr,n , threshold);
cout<<ans;
}