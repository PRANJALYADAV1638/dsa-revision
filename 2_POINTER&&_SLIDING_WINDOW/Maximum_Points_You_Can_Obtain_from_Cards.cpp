#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int solve(vector<int> arr, int k ){
    int ans=0;
    int final=0;
    int left=0;
    int right=0;
    while(right<k&&right<arr.size()){
        ans+=arr[right];
        right++;
    }
    final=ans;
    while(left<k){
        right--;
        ans-=arr[right];
        ans+=arr[arr.size()-1-left];
        final=max(ans,final);
        left++;
    }
    return final;
}
int main(){
vector<int> arr={6,2,3,4,5,6,1};
int k;
cin>>k;
int ans=solve(arr,k);
cout<<ans;
}