#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    void solve(string &digits, vector<string> &mp, string &com,
               vector<string> &ans, int no);

    void chooseLetters(string &digits, vector<string> &mp, string &com,
                       vector<string> &ans, int no, int idx) {

        if (idx == mp[digits[no] - '0'].size())
            return;

        com.push_back(mp[digits[no] - '0'][idx]);
        solve(digits, mp, com, ans, no + 1);
        com.pop_back();

        chooseLetters(digits, mp, com, ans, no, idx + 1);
    }

    void solve(string &digits, vector<string> &mp, string &com,
               vector<string> &ans, int no) {

        if (no == digits.size()) {
            ans.push_back(com);
            return;
        }

        chooseLetters(digits, mp, com, ans, no, 0);
    }

    vector<string> letterCombinations(string digits) {

        vector<string> ans;

        if (digits.empty())
            return ans;

        vector<string> mp = {
            "", "", "abc", "def", "ghi",
            "jkl", "mno", "pqrs", "tuv", "wxyz"
        };

        string com = "";

        solve(digits, mp, com, ans, 0);

        return ans;
    }
};

int main() {
    Solution obj;

    string digits;
    cin >> digits;

    vector<string> ans = obj.letterCombinations(digits);

    for (string s : ans)
        cout << s << " ";

    return 0;
}