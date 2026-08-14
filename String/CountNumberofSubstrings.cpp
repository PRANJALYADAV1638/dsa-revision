#include<iostream>
#include<bits/stdc++.h>
using namespace std ;
int atmost(string s ,int k){
unordered_map<char,int> freq;
int left=0;
int ans=0;
for(int b=0;b<s.length();b++){
    freq[s[b]]++;
    while(freq.size()>k){
        freq[s[left]]--;
        if(freq[s[left]]==0)freq.erase(s[left]);
        left++;
    }
    ans += b-left+1;
}
return ans;
}
int main(){
    string s="pqpqs";
    int k;
    cin>>k;
    int left=0;
    vector<int> fre(26,0);
    
   int ans=atmost(s,k)-atmost(s,k-1);
cout<<ans;
}