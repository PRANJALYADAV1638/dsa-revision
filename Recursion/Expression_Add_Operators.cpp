#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:

    void solve(string &num, int target, string till,
               long long curr, long long prev,
               vector<string> &ans, int idx) {

        if (idx == num.size()) {
            if (curr == target)
                ans.push_back(till);
            return;
        }

        long long no = 0;

        for (int b = idx; b < num.size(); b++) {

            if (b > idx && num[idx] == '0')
                break;

            no = no * 10 + (num[b] - '0');
            string temp = num.substr(idx, b - idx + 1);

            if (idx == 0) {

                solve(num, target, temp,
                      no, no, ans, b + 1);
            }
            else {

                solve(num, target,
                      till + "+" + temp,
                      curr + no,
                      no,
                      ans, b + 1);

                solve(num, target,
                      till + "-" + temp,
                      curr - no,
                      -no,
                      ans, b + 1);

                solve(num, target,
                      till + "*" + temp,
                      curr - prev + prev * no,
                      prev * no,
                      ans, b + 1);
            }
        }
    }

    vector<string> addOperators(string num, int target) {

        vector<string> ans;
        string till = "";

        solve(num, target, till, 0, 0, ans, 0);

        return ans;
    }
};

int main() {
    Solution obj;

    string num;
    int target;

    cout << "Enter numeric string: ";
    cin >> num;

    cout << "Enter target: ";
    cin >> target;

    vector<string> ans = obj.addOperators(num, target);

    cout << "\nPossible Expressions:\n";
    for (const string &expr : ans) {
        cout << expr << '\n';
    }

    return 0;
}