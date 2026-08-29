#include <bits/stdc++.h>
using namespace std;

void solve(vector<int>& arr, vector<vector<int>>& ans, vector<int>& combination, int idx, int target){
        if(target == 0){
            ans.push_back(combination);
            return;
        }

        for(int i = idx; i < arr.size(); i++){
            // skip duplicates
            if(i > idx && arr[i] == arr[i-1]) continue;

            if(arr[i] > target) break; // pruning
            combination.push_back(arr[i]);
            solve(arr, ans, combination, i+1, target - arr[i]);
            combination.pop_back();
            
        }
    }


int main() {
    vector<int> arr = {4, 9, 2, 5, 1};

    int target;
    cin >> target;

    vector<vector<int>> ans;
    vector<int> curr;
sort(arr.begin(),arr.end());
    solve(arr, ans, curr, 0, target);

    for (auto final : ans) {
        for (auto x : final)
            cout << x << " ";
        cout << "\n";
    }
}