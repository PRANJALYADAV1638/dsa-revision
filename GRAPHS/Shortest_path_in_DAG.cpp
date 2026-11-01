#include<iostream>
#include<vector>
#include<queue>
#include<climits>
using namespace std;
vector<int> solve(int n , int m , vector<vector<int>> edge){
    vector<int> ans(n,INT_MAX);
    ans[0]=0;
    vector<int> indegree(n,0);
    vector<vector<pair<int,int>>> adj(n);
    queue<int> q;
    for(int b=0;b<m;b++){
       adj[edge[b][0]].push_back({edge[b][1],edge[b][2]});
indegree[edge[b][1]]++;    }
    for(int b=0;b<n;b++){
    if(indegree[b]==0){
        q.push(b);
    }    
    }
    while(!q.empty()){
        int node=q.front();
        q.pop();
        for(auto it: adj[node]){
            int v=it.first;
            int wt=it.second;
             if(ans[node] != INT_MAX &&
               ans[node] + wt < ans[v]) {
                ans[v] = ans[node] + wt;
            }
            indegree[v]--;
            if(indegree[v]==0){
                q.push(v);
            }
        }
    }
    for(int b=0;b<n;b++){
        if(ans[b]==INT_MAX){
            ans[b]=-1;
        }
    }
    return ans;
}
int main(){
    int n;
    int m ;
    cin>>n;
    cin>>m;
    vector<vector<int>> edge={{0,1,2},{0,2,1}};
    vector<int> ans=solve(n,m,edge);
    for(int b: ans){
        cout<<b<<" ";
    }
}