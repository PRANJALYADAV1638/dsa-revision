#include<iostream>
#include<vector>
#include<queue>
#include<unordered_set>
using namespace std;
int solve(vector<string > & arr,string begin,string end){
    unordered_set<string> st(arr.begin(),arr.end());
    if(st.find(end) == st.end()) return 0;
    int count=1;
    queue<string> q;
    q.push(begin);
    while(!q.empty()){
        int n =q.size();
        for(int b=0;b<n;b++){
     string node=q.front();
     q.pop();
     if(node==end)return count;
for(int b=0;b<node.size();b++){
    char original=node[b];
    for(char c='a';c<='z';c++){
        node[b]=c;
        if(st.find(node)!=st.end()){
        q.push(node);
        st.erase(node);
        }
    }
    node[b]=original;
}
        }
count++;
    }
    return 0;
}
int main(){
    string begin="hit";
    string end="cog";
    vector<string> arr={"hot","dot","dog","lot","log","cog"};
    int ans=solve(arr,begin,end);
    cout<<ans;
}