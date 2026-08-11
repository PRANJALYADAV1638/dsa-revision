#include<iostream>
using namespace std;
#include<bits/stdc++.h>
int main(){
   string s= " -042";
   int i=0;
   int n =s.length();
   long long ans=0;
   int sign=1;
   while(i<n&&s[i]==' '){
    i++;
   }
   if(i<n){
    if(s[i]=='+'){
        sign=1;
        i++;

    }
    else if(s[i]=='-'){
        sign=-1;
        i++;
    }
   }
   while(i<n&&s[i]>='0'&&s[i]<='9'){
ans=ans*10+(s[i]-'0');
   i++;
   if(sign==1&&ans>INT_MAX){
    cout<<INT_MAX;
    return 0;
   }
   else if(sign==-1&&-ans<INT_MIN){
    cout<<INT_MIN;
    return 0;
   }
}
   cout<<sign*ans;
}