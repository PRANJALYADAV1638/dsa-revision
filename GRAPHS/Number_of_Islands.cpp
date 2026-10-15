
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void dfs(int row,int col, vector<vector<char>> &grid){
    if(row<0||col<0||row>=grid.size()||col>=grid[0].size()||grid[row][col]=='0')return ;
    grid[row][col]='0';
    dfs(row+1,col,grid);
    dfs(row-1,col,grid);
    dfs(row,col+1,grid);
    dfs(row,col-1,grid);

}
int main() {
    vector<vector<char>> grid = {
        {'1', '1', '1', '1', '0'},
        {'1', '1', '0', '1', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '0', '0', '0'}
    };
    int ans=0;
for(int b=0;b<grid.size();b++){
    for(int c=0;c<grid[0].size();c++){
        if(grid[b][c]=='1'){
ans++;
dfs(b,c,grid);
        }
    }
}
cout<<ans;
    return 0;
}

