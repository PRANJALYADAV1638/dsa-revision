#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    vector<int> nse(vector<int> &arr) {
        int n = arr.size();
        vector<int> ans(n);
        stack<int> st;

        for(int b = n-1; b >= 0; b--) {

            while(!st.empty() && arr[b] < arr[st.top()]) {
                st.pop();
            }

            if(st.empty()) {
                ans[b] = n;
            }
            else {
                ans[b] = st.top();
            }

            st.push(b);
        }

        return ans;
    }

    vector<int> pse(vector<int> &arr) {
        int n = arr.size();
        stack<int> st;
        vector<int> ans(n);

        for(int b = 0; b < n; b++) {

            while(!st.empty() && arr[b] <= arr[st.top()]) {
                st.pop();
            }

            if(st.empty()) {
                ans[b] = -1;
            }
            else {
                ans[b] = st.top();
            }

            st.push(b);
        }

        return ans;
    }

    int sumSubarrayMins(vector<int>& arr) {

        vector<int> p = pse(arr);
        vector<int> n = nse(arr);

        long long ans = 0;
        long long mod = 1e9 + 7;

        for(int b = 0; b < arr.size(); b++) {

            long long left = b - p[b];
            long long right = n[b] - b;

            ans = (ans + 1LL * arr[b] * left * right) % mod;
        }

        return ans;
    }
};


int main() {

    Solution obj;

    vector<int> arr = {3, 1, 2, 4};

    cout << obj.sumSubarrayMins(arr) << endl;

    return 0;
}