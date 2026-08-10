
/*
#include<iostream>
using namespace std;
#include<bits/stdc++.h>
bool rotate(string s , string goal){
    if(s.length()!=goal.length())return false;
    for(int b=0;b<s.length();b++){
rotate(s.begin(), s.begin() + 1, s.end());
if(s==goal)return true;
    }
    return false;
}
int main(){
    string s = "abcde", goal = "abced";
    if(rotate(s,goal)){
        cout<<"true";
    }
    else{
        cout<<"false";
    }
}
    */


// OPTIMAL
    
#include<iostream>
using namespace std;
#include<bits/stdc++.h>
bool rotate(string s , string goal){
    if(s.length()!=goal.length())return false;
   string temp=s+s;
 return  temp.find(goal) != string::npos;
}
int main(){
    string s = "abcde", goal = "abced";
    if(rotate(s,goal)){
        cout<<"true";
    }
    else{
        cout<<"false";
    }
}