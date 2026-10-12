
#include <iostream>
#include <string>
#include <climits>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.length();
        int m = t.length();

        int minLen = INT_MAX;
        int start = -1;

        int i = 0, j = 0;

        while (i < n) {
            if (s[i] == t[j]) {
                j++;
            }

            if (j == m) {
                int end = i;
                j--;

                while (j >= 0) {
                    if (s[i] == t[j]) {
                        j--;
                    }
                    i--;
                }

                i++;

                if (end - i + 1 < minLen) {
                    minLen = end - i + 1;
                    start = i;
                }

                j = 0;
            }

            i++;
        }

        if (start == -1) {
            return "";
        }

        return s.substr(start, minLen);
    }
};

int main() {
    Solution obj;

    string s = "abcdebdde";
    string t = "bde";

    string result = obj.minWindow(s, t);

    cout << "Minimum Window Subsequence: " << result << endl;

    return 0;
}

