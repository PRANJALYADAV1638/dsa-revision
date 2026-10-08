#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int left = 0;
        int ans = 0;

        unordered_map<int, int> freq;

        for(int right = 0; right < fruits.size(); right++) {

            freq[fruits[right]]++;

            while(freq.size() > 2) {

                freq[fruits[left]]--;

                if(freq[fruits[left]] == 0) {
                    freq.erase(fruits[left]);
                }

                left++;
            }

            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};

int main() {

    Solution obj;

    vector<int> fruits = {1, 2, 1, 2, 3, 2, 2};

    cout << obj.totalFruit(fruits) << endl;

    return 0;
}