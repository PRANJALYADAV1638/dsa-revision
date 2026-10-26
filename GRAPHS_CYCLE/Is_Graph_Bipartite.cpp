#include<iostream>
#include<bits/stdc++.h>
using namespace std;
bool ischeck(vector<vector<int>> &graph){
    vector<int> color(graph.size(),-1);
    for(int b=0;b<graph.size();b++){
        if(color[b]==-1){
            queue<int> q;
            q.push(b);
color[b]=0;
while(!q.empty()){
int node=q.front();
q.pop();
for(int adj:graph[node]){
    if(color[adj]==-1){
        color[adj]=1-color[node];
        q.push(adj);
    }
    else if (color[adj]==color[node]){
        return false;
    }
}
}
        }
    }
    return true;
}
int main(){
    vector<vector<int>> graph={{1,3},{0,2},{1,3},{0,2}};
    if(ischeck(graph)){
        cout<<"true";
    }
    else{
        cout<<"false";
    }
}