#include<iostream>
#include<bits/stdc++.h>
using namespace std;
vector<int> parent;
vector<int> rnk;
vector<int> size;
int findparent(int x){
    if(parent[x]==x)return x;
return parent[x]=findparent(parent[x]);
}

void ubr(int x, int y){
int parent_x=findparent(x);
int parent_y=findparent(y);
if(parent_x==parent_y)return ;
if(rnk[parent_x]==rnk[parent_y]){
    parent[parent_y]=parent_x;
    rnk[parent_x]++;
}
else if(rnk[parent_x]<rnk[parent_y]){
parent[parent_x]=parent_y;
}
else{
 parent[parent_y]=parent_x;   
}


}
void ubs(int x, int y){
int parent_x=findparent(x);
int parent_y=findparent(y);
if(parent_x==parent_y)return;
if(size[parent_x]>size[parent_y]){
    parent[parent_y]=parent_x;
size[parent_x]+=size[parent_y];
}
else{
    parent[parent_x]=parent_y;
    size[parent_y]+=size[parent_x];
}
}


int main(){
vector<string> input={"dis","ubr","ubs","ubr","find","find"};
vector<vector<int>> arr={{5},{0,1},{3,4},{1,2},{0,2},{1,3}};
int n =arr[0][0];
parent.resize(n);
rnk.resize(n,0);
size.resize(n,1);
for(int b=0;b<n;b++){
    parent[b]=b;
}




for(int b=0;b<input.size();b++){
    if(input[b]=="dis"){
        cout<<"NULL ";
    }
    if(input[b]=="ubr"){
        int x=arr[b][0];
        int y=arr[b][1];
        ubr(x,y);
        cout<<"NULL ";
    }
    if(input[b]=="ubs"){
        int x=arr[b][0];
        int y=arr[b][1];
        ubs(x,y);
        cout<<"NULL ";
    }
    if(input[b]=="find"){
        int x=arr[b][0];
        int y =arr[b][1];
        if(findparent(x)==findparent(y)){
            cout<<"true ";
        }
        else{
            cout<<"false ";
        }
    }
}
}