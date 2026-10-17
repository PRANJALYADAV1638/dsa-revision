#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int bfs(vector<vector<int>> &arr,queue<pair<int,int>> &q){
int time=-1;
while(!q.empty()){
    int n =q.size();
    time++;
    for(int b=0;b<n;b++){
    auto node=q.front();
    q.pop();
    int row=node.first;
    int col=node.second;
if(row+1<arr.size()&&arr[row+1][col]==1){
    arr[row+1][col]=2;
    q.push({row+1,col});
}
if(col+1<arr[0].size()&&arr[row][col+1]==1){
    arr[row][col+1]=2;
    q.push({row,col+1});

}
if(row-1>=0&&arr[row-1][col]==1){
    arr[row-1][col]=2;
    q.push({row-1,col});
}
if(col-1>=0&&arr[row][col-1]==1){
    arr[row][col-1]=2;
    q.push({row,col-1});
}
    }
}
for(int b=0;b<arr.size();b++){
    for(int c=0;c<arr[0].size();c++){
        if(arr[b][c]==1){
            return -1;
        }
    }
}
return max(0, time);}
int main(){
    vector<vector<int>> arr={{2,1,1},{1,1,0},{0,1,1}};
    queue<pair<int , int >>q;
    for(int b=0;b<arr.size();b++){
        for(int c=0;c<arr[0].size();c++){
            if(arr[b][c]==2){
                q.push({b,c});
            }
        }
    }
    int ans=bfs(arr,q);
    cout<<ans;
}