#include<iostream>
using namespace std;
int main(){
    int n ;
    cin>>n;
    if((n & (n+1)) == 0)
            return n;

        int ans= n | (n+1);
   cout<<ans;
}