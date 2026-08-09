#include<iostream>
using namespace std;
string longestodd(string s){
int x=-1;
for(int b=s.length()-1;b>=0;b--){
    if(s[b]%2!=0){
x=b;
break;
    }
}
return s.substr(0,x+1);
}

int main(){
    string num="354272244";
string ans=" ";
ans=longestodd(num);
cout<<ans;
}