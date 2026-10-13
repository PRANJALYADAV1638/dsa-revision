#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int atmost(vector<int> &nums,int goal){
    if (goal < 0) return 0;
    int left=0;
    int ans=0;
    int sum=0;
    for(int right=0;right<nums.size();right++){
        sum+=nums[right];
        while(sum>goal){
            sum-=nums[left];
            left++;
        }
        ans+=right-left+1;
    }
    return ans;
}
int main(){
    vector<int> nums={1,0,1,0,1};
    int goal;
    cin>>goal;
    int ans=atmost(nums,goal)-atmost(nums,goal-1);
    cout<<ans;
}