/*     queue based



#include<iostream>
#include<bits/stdc++.h>
using namespace std;
vector<int> solve(vector<vector<int>> &arr,int n , int s){
    vector<vector<pair<int, int >> >adj(n);
    for(int b=0;b<arr.size();b++){
        adj[arr[b][0]].push_back({arr[b][1],arr[b][2]});
    }
    vector<int> dist(n,INT_MAX);
    dist[0]=0;
    queue<pair<int ,int>>q;
    q.push({s,0});
    while(!q.empty()){
        int d=q.front().second;
        int node=q.front().first;
        q.pop();
        for(auto it :adj[node]){
          int cost=it.second;
          int newnode=it.first;
          int newdist=cost+d;
          if(newdist<dist[newnode]){
            dist[newnode]=newdist;
            q.push({newnode,newdist});
          }
        }
    }
    return dist;
}
int main(){
    vector<vector<int>> arr={{3,2,6},{5,3,1},{0,1,5},{1,5,-3},
{1,2,-2},{3,4,-2},{2,4,3}};
int n=6;
int s=0;
vector<int> ans= solve(arr,n,s);
 
for(int x:ans){
    cout<<x<<" ";
}
}



/*
Why do we need Bellman-Ford Algorithm?
Bellman-Ford is a shortest-path algorithm used to find the shortest distance from a single source to all other vertices in a weighted graph.

Why do we use it?
1. It works with negative edge weights, unlike Dijkstra.
2. It can detect negative weight cycles reachable from the source.
3. It is useful in graphs where edge weights can be positive as well as negative.
4. It repeatedly relaxes all edges to ensure shortest distances are calculated.
*/



#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<int> solve(vector<vector<int>>& arr, int n, int s) {

    vector<int> dist(n, INT_MAX);

    dist[s] = 0;

    for(int i = 0; i < n-1; i++) {

        for(int b = 0; b < arr.size(); b++) {

            int u = arr[b][0];
            int v = arr[b][1];
            int wt = arr[b][2];

            if(dist[u] != INT_MAX &&
               dist[u] + wt < dist[v]) {

                dist[v] = dist[u] + wt;
            }
        }
    }

    
    for(int b = 0; b < arr.size(); b++) {

        int u = arr[b][0];
        int v = arr[b][1];
        int wt = arr[b][2];

        if(dist[u] != INT_MAX &&
           dist[u] + wt < dist[v]) {

            cout << "Negative cycle detected";
            return {};
        }
    }

    return dist;
}

int main() {

    vector<vector<int>> arr = {
        {3,2,6},
        {5,3,1},
        {0,1,5},
        {1,5,-3},
        {1,2,-2},
        {3,4,-2},
        {2,4,3}
    };

    int n = 6;
    int s = 0;

    vector<int> ans = solve(arr,n,s);

    for(int x : ans) {
        cout << x << " ";
    }
}
