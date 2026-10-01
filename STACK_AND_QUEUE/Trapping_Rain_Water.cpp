#include<iostream> 
#include<bits/stdc++.h>
using namespace std;
int solve(vector<int> height){
    int left=0;
    int leftmax=0;
    int right=height.size()-1;
    int rightmax=height.size()-1;
    int area=0;
    while(left<=right){
        if(height[left]<=height[right]){
            if(height[left]>=height[leftmax]){
                leftmax=left;
            }
            else{
                area+=height[leftmax]-height[left];
            }
            left++;
        }
        else{
            if(height[right]>=height[rightmax]){
rightmax=right;
            }
            else{
                area+=height[rightmax]-height[right];
            }
            right--;
        }
    }
    return area;
}
int main(){
vector<int> height = {
        0, 1, 0, 2, 1, 0, 
        1, 3, 2, 1, 2, 1
    };
cout<<"trapperd water "<<solve(height);
}