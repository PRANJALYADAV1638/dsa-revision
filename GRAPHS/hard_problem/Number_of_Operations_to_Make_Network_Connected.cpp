
/*
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int solve(int n , vector<vector<int>> &arr){
    vector<vector<int>> adj(n);
    for(int b=0;b<arr.size();b++){
        adj[arr[b][0]].push_back(arr[b][1]);
        adj[arr[b][1]].push_back(arr[b][0]);
    }
    vector<bool> visit(n,false);
    int count=0;
    if(arr.size()<n-1)return -1;
    for(int b=0;b<n;b++){
        if(visit[b]==false){
            count++;
            queue<int> q;
        q.push(b);
        visit[b]=true;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(int it:adj[node]){
                if(visit[it]==false){
                    visit[it]=true;
                    q.push(it);
                }
            }
        }
    }
    }
    return count-1;
}
int main(){
    vector<vector<int>> arr= {{0,1},{0,2},{0,3},{1,2},{1,3}};
    int n =6;
    int ans= solve(n , arr);
    cout<<ans;
}

*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
vector<int> parent;
vector<int> size;
int findparent(int num){
    if(parent[num]==num)return num;
    return parent[num]=findparent(parent[num]);
}
void unionbysize(int x ,int y){
   int px=findparent(x);
   int py=findparent(y);
if(px==py)return;
if(size[px]>size[py]){
    parent[py]=px;
    size[px]+=size[py];
}
else{
    parent[px]=py;
    size[py]+=size[px];
}

    }
int solve(int n , vector<vector<int>> arr){
if(arr.size()<n-1)return -1;
parent.resize(n);
size.assign(n,1);
for(int b=0;b<n;b++){
    parent[b]=b;
}
int count=n;
for(int b=0;b<arr.size();b++){
    int px=findparent(arr[b][0]);
    int py=findparent(arr[b][1]);
    if(px!=py){
        unionbysize(px,py);
        count--;
    }
}
return count-1;
};
int main(){
    int n =6;
    vector<vector<int>> arr={{0,1},{0,2},{0,3},{1,2},{1,3}};
    int ans=solve(n,arr);
   cout<<ans; 
}