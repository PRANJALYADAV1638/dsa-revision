#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:

    vector<int> pse(vector<int> &nums) {
        stack<int> st;
        vector<int> ans(nums.size());

        for (int b = 0; b < nums.size(); b++) {
            while (!st.empty() && nums[st.top()] > nums[b]) {
                st.pop();
            }

            if (st.empty()) {
                ans[b] = -1;
            }
            else {
                ans[b] = st.top();
            }

            st.push(b);
        }

        return ans;
    }

    vector<int> nse(vector<int> &nums) {
        vector<int> ans(nums.size());
        stack<int> st;

        for (int b = nums.size() - 1; b >= 0; b--) {
            while (!st.empty() && nums[st.top()] >= nums[b]) {
                st.pop();
            }

            if (st.empty()) {
                ans[b] = nums.size();
            }
            else {
                ans[b] = st.top();
            }

            st.push(b);
        }

        return ans;
    }

    vector<int> pge(vector<int> &nums) {
        stack<int> st;
        vector<int> ans(nums.size());

        for (int b = 0; b < nums.size(); b++) {
            while (!st.empty() && nums[st.top()] < nums[b]) {
                st.pop();
            }

            if (st.empty()) {
                ans[b] = -1;
            }
            else {
                ans[b] = st.top();
            }

            st.push(b);
        }

        return ans;
    }

    vector<int> nge(vector<int> &nums) {
        vector<int> ans(nums.size());
        stack<int> st;

        for (int b = nums.size() - 1; b >= 0; b--) {
            while (!st.empty() && nums[st.top()] <= nums[b]) {
                st.pop();
            }

            if (st.empty()) {
                ans[b] = nums.size();
            }
            else {
                ans[b] = st.top();
            }

            st.push(b);
        }

        return ans;
    }

    long long subArrayRanges(vector<int>& arr) {

        vector<int> p = pse(arr);
        vector<int> n = nse(arr);

        long long total = 0;

        for (int b = 0; b < arr.size(); b++) {

            long long left = b - p[b];
            long long right = n[b] - b;

            total = total + 1LL * arr[b] * left * right;
        }

        vector<int> x = pge(arr);
        vector<int> y = nge(arr);

        long long total2 = 0;

        for (int b = 0; b < arr.size(); b++) {

            long long left1 = b - x[b];
            long long right1 = y[b] - b;

            total2 = total2 + 1LL * arr[b] * left1 * right1;
        }

        long long final = total2 - total;

        return final;
    }
};


int main() {

    Solution obj;

    vector<int> arr = {1, 2, 3};

    long long answer = obj.subArrayRanges(arr);

    cout << "Sum of Subarray Ranges = " << answer << endl;

    return 0;
}