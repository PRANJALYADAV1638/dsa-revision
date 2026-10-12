#include<iostream>
#include<bits/stdc++.h>
using namespace std;
string solve(string s , string t){
    vector<int> mp(128,0);
    for(int b:t){
mp[b]++;
    }
    int left=0;
    int start=0;
    int count=t.length();
    int minlen=INT_MAX;
  for(int right=0;right<s.length();right++){
    if(mp[s[right]]>0){
        count--;
    }
    mp[s[right]]--;
    while(count==0){
        if(right-left+1<minlen){
            minlen=right-left+1;
            start=left;
        }
        mp[s[left]]++;
        if(mp[s[left]]>0){
            count++;
        }
        left++;
    }
  }
  return minlen==INT_MAX?"":s.substr(start,minlen);
}
int main(){
string s = "ADOBECODEBANC", t = "ABC";
string ans=solve(s,t);
cout<<ans;
}