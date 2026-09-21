#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> st;
        int n = nums.size();
        vector<int> ans(n);

        for (int b = 2 * n - 1; b >= 0; b--) {
            int idx = b % n;

            while (!st.empty() && st.top() <= nums[idx]) {
                st.pop();
            }

            if (st.empty()) {
                ans[idx] = -1;
            }
            else {
                ans[idx] = st.top();
            }

            st.push(nums[idx]);
        }

        return ans;
    }
};

int main() {
    Solution s;

    vector<int> nums = {1, 2, 1};

    vector<int> ans = s.nextGreaterElements(nums);

    for (int x : ans) {
        cout << x << " ";
    }

    return 0;
}