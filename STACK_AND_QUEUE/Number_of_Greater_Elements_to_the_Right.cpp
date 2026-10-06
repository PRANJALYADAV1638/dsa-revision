#include<iostream>
#include<bits/stdc++.h>
using namespace std;
vector<int> nge(vector<int> arr){
vector<int> ans(arr.size());
stack<int> st;
for(int b=arr.size()-1;b>=0;b--){
    while(!st.empty()&&arr[st.top()]<arr[b]){
 st.pop();
    }
    if(!st.empty()){
ans[b]=st.top();
    }
    else{
ans[b]=arr.size()-1;
    }
    st.push(b);
}
return ans;
}
int main(){
    vector<int> arr={3, 4, 2, 7, 5, 8, 10, 6};
    vector<int> arr2={0,5};
    vector<int> ans;
    
    for(int b=0;b<arr2.size();b++){
         int count=0;
         for(int j=arr2[b]+1;j<arr.size();j++){
            if(arr[j]>arr[arr2[b]]){
                count++;
            }
         }
         ans.push_back(count);
    }
     for(int b=0;b<ans.size();b++){
        cout<<ans[b]<<" ";
    }
}