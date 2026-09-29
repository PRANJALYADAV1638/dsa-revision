#include <iostream>
#include <vector>
#include <deque>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        deque<int> q;
        int left = 0;
        int right = 0;
        vector<int> ans;

        while(right < nums.size()) {

            while(!q.empty() && nums[q.back()] < nums[right]) {
                q.pop_back();
            }

            q.push_back(right);

            if(right - left + 1 == k) {

                ans.push_back(nums[q.front()]);

                if(left == q.front()) {
                    q.pop_front();
                    left++;
                }
                else {
                    left++;
                }
            }

            right++;
        }

        return ans;
    }
};

int main() {

    Solution obj;

    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;

    vector<int> ans = obj.maxSlidingWindow(nums, k);

    cout << "Maximum of each window: ";

    for(int x : ans) {
        cout << x << " ";
    }

    cout << endl;

    return 0;
}