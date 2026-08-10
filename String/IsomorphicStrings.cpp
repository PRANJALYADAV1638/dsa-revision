#include<iostream>
#include<bits/stdc++.h>
using namespace std;
bool solve(string s , string t){
    unordered_map<char,char> mp;
        unordered_map<char,char> mp2;

    if(s.length()!=t.length()){
        return false;
    }
    for(int b=0;b<s.length();b++){
       if( mp.find(s[b])==mp.end()){
         mp[s[b]]=t[b];
        }
        else{
       if(mp[s[b]]!=t[b]){
        return false;
       }
    }
    if (mp2.find(t[b]) == mp2.end())
                mp2[t[b]] = s[b];
            else if (mp2[t[b]] != s[b])
                return false;
}
return true;
    
}
int main(){
    string s="paper";
    string t="tiplr";
   if( solve(s,t)){
   
        cout<<"true";
        return 0;
    }
    cout<<"false";
}