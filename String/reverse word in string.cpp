#include<bits/stdc++.h>
using namespace std;

    string reverseWords(string s) {
        int n =s.length();
        string ans = "";
        reverse(s.begin(),s.end());
   for(int b=0;b<n;b++){
        string word="";
    
        while(b<n&&s[b]!= ' ' ){
            word+= s[b];
            b++;
        }
            reverse(word.begin(),word.end());
            if(word.length()>0){
                ans+= " "+word;
            
        }
   
    }
    return ans.substr(1);
    }
int main(){
    string ans="";
    string s= "the sky is blue";
    ans=reverseWords(s);
    cout<<ans;
}