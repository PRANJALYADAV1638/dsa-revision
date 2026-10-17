#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void dfs(vector<vector<char >> &arr,int row, int col){
    if(row>=arr.size()||col>=arr[0].size()||row<0||col<0||arr[row][col]!='O')return ;
    arr[row][col]='v';
    dfs(arr,row+1,col);
    dfs(arr,row-1,col);
    dfs(arr,row,col+1);
    dfs(arr,row,col-1);
}
int main(){
    vector<vector<char >> arr={{'X','X','X','X'},{'X','O','O','X'},{'X','X','O','X'},{'X','O','X','X'}};
    int n=arr.size();
    int m =arr[0].size();
    if(m==0)return 0;
    if(n==0)return 0;
    for(int b=0;b<n;b++){
dfs(arr,b,0);
dfs(arr,b,m-1);
    }
    for(int b=0;b<m;b++){
dfs(arr,0,b);
dfs(arr,n-1,b);
    }
    for(int b=0;b<n;b++){
        for(int c=0;c<m;c++){
if(arr[b][c]=='O'){
    arr[b][c]='X';
}
else if(arr[b][c]=='v'){
    arr[b][c]='O';
}
        }
    }
    for(int b=0;b<n;b++){
        for(int c=0;c<m;c++){
            cout<<arr[b][c]<<" ";
        }
        cout<<endl;
    }
}