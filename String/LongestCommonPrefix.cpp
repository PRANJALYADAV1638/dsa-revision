#include<iostream>
using namespace std;
#include<bits/stdc++.h>
string find(vector<string> &s){

    string ans="";
    for(int b=0;b<s[0].size();b++){
         char ch=s[0][b];
         for(int c=1;c<s.size();c++){
            if(b>=s[c].size()||s[c][b]!=ch){
                return ans;
            }
            
            
        }
        ans+=ch;
    }
    return ans;
}
int main(){
    vector<string> s={"flower","flow","flight"};
string ans="";
ans=find(s);
cout<<ans;
}