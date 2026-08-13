/*

#include<iostream>
using namespace std;
#include<bits/stdc++.h>
bool solve(string s , string t){
    if(s.length()!=t.length())return false;
    int freq1[26]={0};
    int freq2[26]={0};
    for(char c:s){
        freq1[c-'a']++;
    }
    for(char c:t){
        freq2[c-'a']++;
    }
  for(int i = 0; i < 26; i++){
    if(freq1[i] != freq2[i])
        return false;
}

return true;

}
int main(){
    string s = "anagram", t = "nagaram";
    if(solve(s,t)){
        cout<<"true";
    }
    else{
        cout<<"false";
    }
}

*/





//  1 freq only



#include<iostream>
using namespace std;
#include<bits/stdc++.h>
bool solve(string s , string t){
    if(s.length()!=t.length())return false;
    int freq1[26]={0};
    
    for(char c:s){
        freq1[c-'a']++;
    }
    for(char c:t){
        freq1[c-'a']--;
    }
  for(int i = 0; i < 26; i++){
    if(freq1[i] != 0)
        return false;
}

return true;

}
int main(){
    string s = "anagram", t = "nagaram";
    if(solve(s,t)){
        cout<<"true";
    }
    else{
        cout<<"false";
    }
}