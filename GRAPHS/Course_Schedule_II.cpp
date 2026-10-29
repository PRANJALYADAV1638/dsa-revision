#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<int> solve(vector<vector<int>> &arr,int num){
    vector<int> indegree(num,0);
    vector<vector<int>> adj(num); 
    for(int b=0;b<arr.size();b++){
        int n =arr[b][0];
        int m =arr[b][1];
adj[m].push_back(n);
indegree[n]++;
    }
    queue<int> q;
    for(int b=0;b<num;b++){
        if(indegree[b]==0){
            q.push(b);
        }
    }
    vector<int> ans;
    while(!q.empty()){
        int node=q.front();
        q.pop();
ans.push_back(node);
for(int it : adj[node]){
    indegree[it]--;
    if(indegree[it]==0){
        q.push(it);
    }
}
    }
    return ans;
}
int main(){
    int num;
    cin>>num;
    vector<vector<int>> arr={{1,0}};
    vector<int> ans=solve(arr,num);
    for(int it: ans){
        cout<<it<<" ";
    }
}