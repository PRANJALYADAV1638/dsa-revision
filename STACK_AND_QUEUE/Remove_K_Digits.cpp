#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        string ans;

        for(char c : num) {
            while(!st.empty() && k > 0 && st.top() > c) {
                st.pop();
                k--;
            }
            st.push(c);
        }

        while(!st.empty() && k--) {
            st.pop();
        }

        while(!st.empty()) {
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        int i = 0;
        while(i < ans.size() && ans[i] == '0')
            i++;

        ans = ans.substr(i);

        return ans.empty() ? "0" : ans;
    }
};


int main() {

    Solution obj;

    string num = "1432219";
    int k = 3;

    cout << "Answer: " << obj.removeKdigits(num, k) << endl;

    return 0;
}



