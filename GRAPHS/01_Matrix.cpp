#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void bfs(vector<vector<int>> &mat,queue<pair<int , int>> &q){
while(!q.empty()){
    int n =q.size();
    for(int b=0;b<n;b++){
        auto node=q.front();
        q.pop();
        int row=node.first;
        int col=node.second;
          if(row+1<mat.size()&&mat[row+1][col]==-1){
    mat[row+1][col]=mat[row][col]+1;
    q.push({row + 1, col});
   }
   if(col+1<mat[0].size()&&mat[row][col+1]==-1){
    mat[row][col+1]=mat[row][col]+1;
    q.push({row,col+1});
   }
   if(row-1>=0&&mat[row-1][col]==-1){
    mat[row-1][col]=mat[row][col]+1;
    q.push({row-1,col});
   }
   if(col-1>=0&&mat[row][col-1]==-1){
    mat[row][col-1]=mat[row][col]+1;
    q.push({row,col-1});
   }
    }
}
}
int main(){
    vector<vector<int>> arr={{0,0,0},{0,1,0},{1,1,1}};
    queue<pair<int,int>> q;
    for(int b=0;b<arr.size();b++){
        for(int c=0;c<arr[0].size();c++){
            if(arr[b][c]==0){
                q.push({b,c});
            }
            else{
                arr[b][c]=-1;
            }
        }
    }
    bfs(arr,q);
    for(int b=0;b<arr.size();b++){
        for(int c=0;c<arr[0].size();c++){
            cout<<arr[b][c]<<" ";
        }
        cout<<endl;
    }
}