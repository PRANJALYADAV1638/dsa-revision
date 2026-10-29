#include<iostream>
#include<vector>
#include<queue>
using namespace std;
bool solve(vector<vector<int>> &arr,int num){
    int count=0;
    int n =arr.size();
    vector<vector<int>> adj(num);
vector<int> indegree(num,0);
for(auto it: arr){
    int first=it[0];
    int second=it[1];
adj[second].push_back(first);
indegree[first]++;
}

queue<int> q;
for(int b=0;b<num;b++){
    if(indegree[b]==0){
q.push(b);
    }
}
while(!q.empty()){
    int node=q.front();
    q.pop();
    count++;
    for(int b: adj[node]){
        indegree[b]--;
        if(indegree[b]==0){
            q.push(b);
        }
    }
}
return count==num;
}
int main(){
    vector<vector<int>> arr={{1,0}};
    int num;
    cin>>num;
if(solve(arr,num)){
    cout<<"true";
}
else{
    cout<<"false";
}
}