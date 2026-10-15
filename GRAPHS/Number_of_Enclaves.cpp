#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void dfs(vector<vector<int>> &arr, int row, int col){
    if(row<0||col<0||row>=arr.size()||col>=arr[0].size()||arr[row][col]!=1)return ;
    arr[row][col]=0;
    dfs(arr,row+1,col);
    dfs(arr,row-1,col);
    dfs(arr,row,col-1);
    dfs(arr,row,col+1);
}
int solve(vector<vector<int>> &arr){
int ans=0;
int n=arr.size();
int m =arr[0].size();
for(int b=0;b<n;b++){
dfs(arr,b,0);
dfs(arr,b,m-1);
}
for(int c=0;c<m;c++){
dfs(arr,0,c);
dfs(arr,n-1,c);
}
for(int b=0;b<n;b++){
    for(int c=0;c<m;c++){
        if(arr[b][c]==1){
            ans++;
        }
    }
}
return ans;
}
int main(){
    vector<vector<int>> arr={{0,0,0,0},{1,0,1,0},{0,1,1,0},{0,0,0,0}};
    int ans=solve(arr);
    cout<<ans;
}