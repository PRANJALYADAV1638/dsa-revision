#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp;
        stack<int> st;
        vector<int> ans;

        for (int b = nums2.size() - 1; b >= 0; b--) {
            while (!st.empty() && st.top() < nums2[b]) {
                st.pop();
            }

            if (st.empty()) {
                mp[nums2[b]] = -1;
            }
            else {
                mp[nums2[b]] = st.top();
            }

            st.push(nums2[b]);
        }

        for (int b = 0; b < nums1.size(); b++) {
            ans.push_back(mp[nums1[b]]);
        }

        return ans;
    }
};

int main() {
    Solution s;

    vector<int> nums1 = {4, 1, 2};
    vector<int> nums2 = {1, 3, 4, 2};

    vector<int> ans = s.nextGreaterElement(nums1, nums2);

    for (int x : ans) {
        cout << x << " ";
    }

    return 0;
}