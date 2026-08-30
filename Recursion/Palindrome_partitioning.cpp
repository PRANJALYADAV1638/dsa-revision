#include<bits/stdc++.h>
using namespace std;
bool ispalindrome(string com) {
    int i = 0;
    int j = com.size() - 1;

    while (i < j) {
        if (com[i] != com[j])
            return false;

        i++;
        j--;
    }

    return true;
}
void solve(string s,vector<string>& com,string arr,vector<vector<string>> &ans,int idx){
   if(s.empty())return;
   string word="";

   if(idx==s.length()){
    ans.push_back(com);
    return ;
   }
   for(int b=idx;b<s.length();b++){
word.push_back(s[b]);
if(ispalindrome(word)){
    com.push_back(word);
    solve(s,com,arr,ans,b+1);
    com.pop_back();
}
   }
};
int main(){
    string s="aabaa";
    vector<string > com;
    string arr="";
    vector<vector<string>> ans;
    solve(s,com,arr,ans,0);
    for(auto final : ans){

        for(auto last:final){
            
cout<<last<<" ";
            
        }
        cout<<endl;
    }
}