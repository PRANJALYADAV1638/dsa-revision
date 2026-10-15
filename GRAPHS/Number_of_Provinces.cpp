#include<iostream>
using namespace std;
#include<bits/stdc++.h>
void dfs(int stt,vector<vector<int>> &arr, vector<bool> &isvisited){
    isvisited[stt]=true;
for(int b=0;b<arr[0].size();b++){
    if(arr[stt][b]==1&&!isvisited[b]){
        dfs(b,arr,isvisited);
    }
}
}

int solve(vector<vector<int>> arr){
    int count=0;
    vector<bool> isvisited(arr.size(),false);
    for(int b=0;b<arr.size();b++){
        if(!isvisited[b]){
            count++;
            dfs(b,arr,isvisited);
        }
    }
    return count;
}
int main(){
    vector<vector<int>> arr={{1,1,0},{1,1,0},{0,0,1}};
    int ans=solve(arr);
    cout<<ans;
}