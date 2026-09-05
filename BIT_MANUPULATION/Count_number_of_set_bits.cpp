#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n ;
    cin>>n;
     
     int count=0;
    while(n){
        if(n&(1<<0)){
            count++;
        }
        n=n>>1;
    }
cout<<count;
}