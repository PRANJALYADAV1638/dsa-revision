/*
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
    */

   #include <iostream>
#include <vector>
#include <queue>
using namespace std;

void bfs(vector<vector<int>>& arr, int row, int col) {
int n = arr.size();
int m = arr[0].size();

if (arr[row][col] != 1)
    return;

queue<pair<int, int>> q;

q.push({row, col});
arr[row][col] = 0;

int dr[] = {1, -1, 0, 0};
int dc[] = {0, 0, -1, 1};

while (!q.empty()) {
    int r = q.front().first;
    int c = q.front().second;
    q.pop();

    for (int i = 0; i < 4; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];

        if (nr >= 0 && nc >= 0 &&
            nr < n && nc < m &&
            arr[nr][nc] == 1) {

            arr[nr][nc] = 0;
            q.push({nr, nc});
        }
    }
}


}

int solve(vector<vector<int>>& arr) {
int n = arr.size();
int m = arr[0].size();
int ans = 0;


for (int b = 0; b < n; b++) {
    bfs(arr, b, 0);
    bfs(arr, b, m - 1);
}

for (int c = 0; c < m; c++) {
    bfs(arr, 0, c);
    bfs(arr, n - 1, c);
}

for (int b = 0; b < n; b++) {
    for (int c = 0; c < m; c++) {
        if (arr[b][c] == 1) {
            ans++;
        }
    }
}

return ans;

}

int main() {
vector<vector<int>> arr = {
{0, 0, 0, 0},
{1, 0, 1, 0},
{0, 1, 1, 0},
{0, 0, 0, 0}
};

cout << solve(arr) << endl;

return 0;

}
