#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:

    vector<int> pse(vector<int>& heights) {
        vector<int> ans(heights.size());
        stack<int> st;

        for(int b = 0; b < heights.size(); b++) {

            while(!st.empty() && heights[st.top()] > heights[b]) {
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

    vector<int> nse(vector<int>& heights) {
        vector<int> ans(heights.size());
        stack<int> st;

        for(int b = heights.size() - 1; b >= 0; b--) {

            while(!st.empty() && heights[st.top()] > heights[b]) {
                st.pop();
            }

            if(st.empty()) {
                ans[b] = heights.size();
            }
            else {
                ans[b] = st.top();
            }

            st.push(b);
        }

        return ans;
    }

    int largestRectangleArea(vector<int>& heights) {

        int ans = 0;

        vector<int> p = pse(heights);
        vector<int> n = nse(heights);

        for(int b = 0; b < heights.size(); b++) {

            int length = n[b] - p[b] - 1;

            int area = length * heights[b];

            ans = max(area, ans);
        }

        return ans;
    }
};

int main() {

    Solution obj;

    vector<int> heights = {2, 1, 5, 6, 2, 3};

    cout << "Largest Rectangle Area: "
         << obj.largestRectangleArea(heights) << endl;

    return 0;
}