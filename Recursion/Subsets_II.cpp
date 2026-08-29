#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solve(vector<int>& nums, int idx,
               vector<vector<int>>& ans,
               vector<int>& com) {

        if (idx == nums.size()) {
            ans.push_back(com);
            return;
        }

        com.push_back(nums[idx]);
        solve(nums, idx + 1, ans, com);
        com.pop_back();

        int next = idx + 1;
        while (next < nums.size() && nums[next] == nums[next - 1]) {
            next++;
        }

        solve(nums, next, ans, com);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;
        vector<int> com;

        solve(nums, 0, ans, com);

        return ans;
    }
};

int main() {
    Solution obj;

    vector<int> nums = {1, 2, 2};

    vector<vector<int>> ans = obj.subsetsWithDup(nums);

    cout << "Subsets are:\n";

    for (auto &subset : ans) {
        cout << "[ ";
        for (int x : subset) {
            cout << x << " ";
        }
        cout << "]\n";
    }

    return 0;
}