#include<iostream>
using namespace std;
int main(){
    int n ;
    cin>>n;
    int i;
    cin>>i;
    if(n&(1<<i)){
        cout<<"true";
    }
    else{
        cout<<"false";
    }
}