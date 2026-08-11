#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
    string s ="tree";
    unordered_map<char,int> mp;
    for(char c: s){
        mp[c]++;
    }
    vector<string> bucket(s.size()+1);
    for(auto c : mp){
        int freq=c.second;
        char letter=c.first;
        bucket[freq]+=string(freq,letter);
    } 
    string ans="";
    for(int b=bucket.size()-1;b>=0;b--){
ans+=bucket[b];
    }
    cout<<ans;
}