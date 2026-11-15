#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
int solve(vector<vector<int>> &grid){
    int n =grid.size();
    vector<vector<int>> dist(n,vector<int> (n,INT_MAX));
    priority_queue<
    tuple<int,int , int>,
    vector<tuple<int,int, int >>,
    greater<tuple<int,int, int>>
>q;
dist[0][0]=grid[0][0];
q.push({grid[0][0],0,0});
   int dx[]={-1,1,0,0};
   int dy[]={0,0,-1,1};
   while(!q.empty()){
int time = get<0>(q.top());
int row = get<1>(q.top());
int col = get<2>(q.top());
q.pop();
    if(time>dist[row][col])continue;
    if(row==n-1&&col==n-1)return time;
    for(int b=0;b<4;b++){
        int nr=row+dx[b];
        int nc=col+dy[b];
        if(nr>=0&&nc>=0&&nr<n&&nc<n){
  int newtime= max(time,grid[nr][nc]);
  if(newtime<dist[nr][nc]){
    dist[nr][nc]=newtime;
    q.push({newtime,nr,nc});
  }
        }
    }
   }
   return -1;
}
int main(){
vector<vector<int>> grid = {{0, 1, 2, 3, 4},
 {24, 23, 22, 21, 5},
  {12, 13, 14, 15, 16},
   {11, 17, 18, 19, 20},
 {10, 9, 8, 7, 6}};
int ans=solve(grid);
cout<<ans;
}