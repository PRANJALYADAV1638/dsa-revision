#include<iostream>
#include<vector> 
#include<queue>
#include<unordered_set>
using namespace std;
vector<vector<string >> solve(vector<string> arr,string begin,string end){
vector<vector<string> > ans;
vector<string> s;
unordered_set<string> st(arr.begin(),arr.end());
if(st.find(end)==st.end()){
    return ans;
}
queue<vector<string>> q;
q.push({begin});
st.erase(begin);
while(!q.empty()){
    int n=q.size();
    vector<string> used;
    for(int b=0;b<n;b++){
        vector<string> path=q.front();
        q.pop();
        string node=path.back();
        for(int b=0;b<node.size();b++){
            char original=node[b];
            for(char c='a';c<='z';c++){
node[b]=c;
if(st.find(node)!=st.end()){
    path.push_back(node);
    q.push(path);
used.push_back(node);
 if(node == end){
                            ans.push_back(path);
                        }
                         path.pop_back();
            }
        }
        node[b]=original;
    }

 }
 for(auto word:used){
    st.erase(word);
 }
  if(!ans.empty()) break;
}
return ans;
}
int main(){
     string end="cog";
    vector<string> arr={"hot","dot","dog","lot","log","cog"};
    vector<vector<string>> ans;
    string begin="hit";
    ans=solve(arr,begin,end);
    for(auto b:ans){
        for(auto c:b){
            cout<<c<<" ";
        }
        cout<<endl;
    }
}