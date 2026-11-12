#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int solve(vector<vector<int>> &arr){
    int n =arr.size();
    int m=arr[0].size();
    vector<vector<int>> dist(n, vector<int>(m, INT_MAX));

        priority_queue<
            pair<int,pair<int,int>>,
            vector<pair<int,pair<int,int>>>,
            greater<pair<int,pair<int,int>>>
        > pq;
 int dx[] = {-1,0,1,0};
        int dy[] = {0,1,0,-1};
                dist[0][0]=0;
        pq.push({0,{0,0}});
        while(!pq.empty()){
            int effort=pq.top().first;
            int row=pq.top().second.first;
            int col=pq.top().second.second;
            pq.pop();
            if(row==n-1&&col==n-1)return effort;
            
            if(effort > dist[row][col])
                continue;
            for(int b=0;b<4;b++){
                int r= row+dx[b];
                int c=col+dy[b];
  if(r>=0&&c>=0&&r<n&&c<m){
    int neweffort=max(effort,abs(arr[row][col]-arr[r][c]));
    if(neweffort<dist[r][c]){
dist[r][c]=neweffort;
pq.push({neweffort,{r,c}});
    }
  }
            }
        }
        return -1;
}
int main(){
    vector<vector<int>> arr={{1,2,2},{3,8,2},{5,3,5}};
    int ans=solve(arr);
    cout<<ans;
}