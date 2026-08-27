#include<iostream>
#include<bits/stdc++.h>
using namespace std;
vector<string> ans;
void solve(int n ,string s){

    if(n==0)return ;
   if(s.length()==n){
ans.push_back(s);
return ;
   }
solve( n ,s+"0");
if(s.empty()||s.back()!='1'){
    solve(n,s+"1");
}
}
int main(){
    int n ;
    cin>>n;
    string s="";
    solve(n,s);
    for(string final : ans){
        cout<<final<<endl;
    }
}