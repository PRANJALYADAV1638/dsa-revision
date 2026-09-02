#include<bits/stdc++.h>
using namespace std;
bool issafe(vector<vector<int> >&maze,int row,int col){
    if(row < 0 || row >= maze.size() || col < 0 || col >= maze[0].size())
        return false;
if(maze[row][col]==0||maze[row][col]=='#')return false;
return true;
}
void solve(vector<vector<int>> &maze, string path,vector<string> &ans,int row,int col ){
    
    if(row==maze.size()-1&&col==maze[0].size()-1){
        ans.push_back(path);
        return ;
    }
     maze[row][col]='#';
    if(issafe(maze,row+1,col)){
       
        solve(maze,path+'D',ans,row+1,col);
    }
     if(issafe(maze,row-1,col)){

        solve(maze,path+'U',ans,row-1,col);
    }
     if(issafe(maze,row,col+1)){

        solve(maze,path+'R',ans,row,col+1);
    }
     if(issafe(maze,row,col-1)){

        solve(maze,path+'L',ans,row,col-1);
    }
    maze[row][col]=1;
   
}

int main(){
     vector<vector<int>> maze = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 1, 1}
    };
    vector<string> ans;
if(maze[0][0]==0){
    cout<<"not starting point ";
    return 0;
}
string path;
solve(maze,path,ans,0,0);
        for(auto x: ans){
            cout<<x<<endl;
        
    }
}