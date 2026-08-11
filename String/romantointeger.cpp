#include<bits/stdc++.h>
using namespace std;
int main(){
    string s="MCMXCIV";
    unordered_map<char,int> mp={{'M',1000},
{'C',100},
{'D',500},
{'L',50},
{'X',10},
{'V',5},
{'I',1}};
int ans=0;
for(int b=0;b<s.length();b++){
    if(b+1<s.length()){
        if(mp[s[b]]>=mp[s[b+1]]){
        ans+=mp[s[b]];
        }
    else{
        ans-=mp[s[b]];
    }
}
else{
    ans+=mp[s[b]];
}
}
cout<<ans;
}