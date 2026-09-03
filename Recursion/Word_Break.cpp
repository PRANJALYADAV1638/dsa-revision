#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool solve(int idx, string &s, unordered_set<string> &st, vector<int> &dp) {

        if (idx == s.size())
            return true;

        if (dp[idx] != -1)
            return dp[idx];

        string temp = "";

        for (int i = idx; i < s.size(); i++) {

            temp += s[i];

            if (st.count(temp)) {

                if (solve(i + 1, s, st, dp))
                    return dp[idx] = true;
            }
        }

        return dp[idx] = false;
    }

    bool wordBreak(string s, vector<string> &wordDict) {

        unordered_set<string> st(wordDict.begin(), wordDict.end());

        vector<int> dp(s.size(), -1);

        return solve(0, s, st, dp);
    }
};

int main() {

    Solution obj;

    string s;
    int n;

    cout << "Enter the string: ";
    cin >> s;

    cout << "Enter number of words in dictionary: ";
    cin >> n;

    vector<string> wordDict(n);

    cout << "Enter dictionary words:\n";
    for (int i = 0; i < n; i++) {
        cin >> wordDict[i];
    }

    if (obj.wordBreak(s, wordDict))
        cout << "True\n";
    else
        cout << "False\n";

    return 0;
}