#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int atmost(vector<int> &arr,int k ){
    int left=0;
    int count=0;
    int ans=0;
    for(int right=0;right<arr.size();right++){
if(arr[right]%2==1){
    count++;
}
while(count>k){
    if(arr[left]%2==1){
        count--;
    }
    left++;
}
ans+=right-left+1;
    }
    return ans;
}
int main(){
vector<int> arr={1,1,2,1,1};
int k ;
cin>>k;
int ans=atmost(arr,k)-atmost(arr,k-1);
cout<<ans;
}