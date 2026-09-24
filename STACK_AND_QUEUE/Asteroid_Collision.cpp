#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        stack<int> st;

        for (int b = 0; b < asteroids.size(); b++) {
            bool alive = true;

            while (!st.empty() && asteroids[b] < 0 && st.top() > 0) {

                if (st.top() > -asteroids[b]) {
                    alive = false;
                    break;
                }
                else if (st.top() == -asteroids[b]) {
                    st.pop();
                    alive = false;
                    break;
                }
                else {
                    st.pop();
                }
            }

            if (alive) {
                st.push(asteroids[b]);
            }
        }

        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};

int main() {
    Solution s;

    vector<int> asteroids = {5, 10, -5};

    vector<int> ans = s.asteroidCollision(asteroids);

    for (int x : ans) {
        cout << x << " ";
    }

    return 0;
}