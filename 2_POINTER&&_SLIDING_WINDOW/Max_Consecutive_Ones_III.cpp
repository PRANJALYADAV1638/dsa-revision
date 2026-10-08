#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int solve(vector<int> arr,int k){
    int ans=0;
    int left=0;
    int right=0;
    int count=0;
    while(right<arr.size()){
if(arr[right]==0){
    count++;
}
while(count>k){
    if(arr[left]==0){
        count--;
    }
    left++;
}
ans=max(ans,right-left+1);
right++;
    }
    return ans;
}
int main(){
    vector<int> arr={0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1};
    int k ;
    cin>>k;
    int ans=solve(arr,k);
    cout<<ans;

}