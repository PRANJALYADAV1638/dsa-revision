#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int atmost(string s , int k){
    int left=0;
    unordered_map<char,int> mp;
    int ans=0;
    for(int right=0;right<s.length();right++){
mp[s[right]]++;
while(mp.size()>k){
    mp[s[left]]--;
    if(mp[s[left]]==0){
        mp.erase(s[left]);
    }
    left++;
}
ans+=right-left+1;
    }
    return ans;
}
int main(){
   string  s = "abcabc";
   long long n =s.length();
   long long total=(n*(n+1))/2;
   int ans=total-atmost(s,2);
   cout<<ans;
}