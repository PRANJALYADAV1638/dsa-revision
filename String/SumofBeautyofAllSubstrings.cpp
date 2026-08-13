#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int beautySum(string s) {
        int ans = 0;
        int n = s.length();

        for (int left = 0; left < n; left++) {
            vector<int> freq(26, 0);

            for (int right = left; right < n; right++) {
                freq[s[right] - 'a']++;

                int maxFreq = 0;
                int minFreq = INT_MAX;

                for (int f : freq) {
                    if (f > 0) {
                        maxFreq = max(maxFreq, f);
                        minFreq = min(minFreq, f);
                    }
                }

                ans += (maxFreq - minFreq);
            }
        }

        return ans;
    }
};

int main() {
    Solution obj;

    string s;
    cin >> s;

    cout << obj.beautySum(s) << endl;

    return 0;
}