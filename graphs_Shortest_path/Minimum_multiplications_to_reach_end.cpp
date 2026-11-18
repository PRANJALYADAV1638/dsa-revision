/*
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int solve(vector<int> &arr, int stt , int end){
    int mod=100000;
    vector<int> dist(mod,1e9);
    queue<pair<int, int>> q;
    q.push({stt,0});
    dist[stt]=0;
    while (!q.empty())
    {
        int node=q.front().first;
        int step=q.front().second;
        q.pop();
        for(int b=0;b<arr.size();b++){
            int newnumber=(node*arr[b])%mod;
            if(dist[newnumber]==1e9){
dist[newnumber]=step+1;
if(newnumber==end)return step+1;
q.push({newnumber,step+1});
            }
        }
    }
    return -1;
}
int main(){
    vector<int> arr={3,4,65};
    int stt=7;
    int end=66175;
    int ans=solve(arr,stt,end);
    cout<<ans;
}
    */

    #include<iostream>
    #include<bits/stdc++.h>
    using namespace std;
    int solve(vector<int> arr,int stt, int end){
        queue<pair<int, int >> q;
        int mod=100000;
        vector<int> vis(100000,0);
        vis[stt]=1;
    q.push({stt,0});
    while(!q.empty()){
        int node=q.front().first;
        int step=q.front().second;
        q.pop();
        for(int b=0;b<arr.size();b++){
            int newnumber=(node*arr[b])%mod;
            if(newnumber==end)return step+1;
         if(!vis[newnumber]){
            vis[newnumber]=1;
            q.push({newnumber,step+1});
         }
        }
    }
    return -1;
    }
    int main(){
        vector<int> arr={3,4,65};
        int stt=7;
        int end=66175;
        int ans=solve(arr,stt,end);
        cout<<ans;
    }