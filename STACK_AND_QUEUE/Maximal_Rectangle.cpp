#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:

    vector<int> pse(vector<int>& heights) {
        stack<int> st;
        int n = heights.size();
        vector<int> ans(n);

        for (int b = 0; b < n; b++) {

            while (!st.empty() && heights[st.top()] >= heights[b]) {
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

    vector<int> nse(vector<int>& heights) {
        stack<int> st;
        int n = heights.size();
        vector<int> ans(n);

        for (int b = n - 1; b >= 0; b--) {

            while (!st.empty() && heights[st.top()] > heights[b]) {
                st.pop();
            }

            if (st.empty()) {
                ans[b] = n;
            }
            else {
                ans[b] = st.top();
            }

            st.push(b);
        }

        return ans;
    }

    int largestRectangleArea(vector<int>& heights) {

        vector<int> p = pse(heights);
        vector<int> n = nse(heights);

        int ans = 0;

        for (int b = 0; b < heights.size(); b++) {

            int length = n[b] - p[b] - 1;

            int area = length * heights[b];

            ans = max(ans, area);
        }

        return ans;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {

        if (matrix.empty())
            return 0;

        int row = matrix.size();
        int col = matrix[0].size();

        int finalanswer = 0;

        vector<int> height(col, 0);

        for (int b = 0; b < row; b++) {

            for (int j = 0; j < col; j++) {

                if (matrix[b][j] == '1')
                    height[j]++;
                else
                    height[j] = 0;
            }

            int ans = largestRectangleArea(height);

            finalanswer = max(finalanswer, ans);
        }

        return finalanswer;
    }
};


int main() {

    Solution obj;

    vector<vector<char>> matrix = {
        {'1', '0', '1', '0', '0'},
        {'1', '0', '1', '1', '1'},
        {'1', '1', '1', '1', '1'},
        {'1', '0', '0', '1', '0'}
    };

    int answer = obj.maximalRectangle(matrix);

    cout << "Maximum Rectangle Area = " << answer << endl;

    return 0;
}