#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int solve(vector<vector<int>> arr,int n ){
    if(arr[0][0]==1||arr[n-1][n-1]==1)return -1;
        if(n==1) return 1;
    queue<pair<int,pair<int,int>>>q;
    q.push({1,{0,0}});
    arr[0][0]=1;
   int dx[]={-1,-1,-1,0,0,1,1,1};
int dy[]={-1,0,1,-1,1,-1,0,1};
    while(!q.empty()){
        int dist=q.front().first;
        int row=q.front().second.first;
        int col=q.front().second.second;
q.pop();
if(row==n-1&&col==n-1)return dist;
        for(int b=0;b<8;b++){
            int r=row+dx[b];
            int c=col+dy[b];
            if(r>=0&&c>=0&&r<n&&c<n&&arr[r][c]==0){
arr[r][c]=1;
q.push({dist+1,{r,c}});
            }
        }
    }
    return -1;
}
int main(){
    vector<vector<int>> arr={{0,0,0},{1,1,0},{1,1,0}};
    int n=arr.size();
    int ans=solve(arr, n);
    cout<<ans; 
}