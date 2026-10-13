#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int atmost(vector<int> &arr,int k){
    int left=0;
    int ans=0;
    unordered_map<int,int> mp;
    for(int right=0;right<arr.size();right++){
  mp[arr[right]]++;
  while(mp.size()>k){
    mp[arr[left]]--;
    if(mp[arr[left]]==0){
mp.erase(arr[left]);
    }
    left++;
  }
  ans+=right-left+1;
    }
    return ans;
}
int main(){
    vector<int> arr={1,2,1,2,3};
    int k ;
    cin>>k;
    int ans=atmost(arr,k)-atmost(arr,k-1);
    cout<<ans;
}