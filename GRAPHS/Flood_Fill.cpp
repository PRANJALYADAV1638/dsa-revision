#include<iostream>
#include<vector>
using namespace std;
void dfs( vector<vector<int>> &image, int sr, int sc,int color , int old){
    if(sr<0||sc<0||sr>=image.size()||sc>=image.size()||image[sr][sc]!=old)return ;
    image[sr][sc]=color;
    dfs(image,sr+1,sc,color,old);
    dfs(image,sr-1,sc,color,old);
    dfs(image,sr,sc+1,color,old);
    dfs(image,sr,sc-1,color,old);
}
int main(){
vector<vector<int>> image={{1,1,1},{1,1,0},{1,0,1}};
int sr=1;
int sc=1;
int color=2;
int old=image[sr][sc];
dfs(image,sr,sc,color,old);
for(int b=0;b<image.size();b++){
    for(int c=0;c<image[0].size();c++){
        cout<<image[b][c]<<" ";
    }
cout<<endl;
}
}