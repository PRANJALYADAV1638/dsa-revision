#include<iostream>
using namespace std;
#include<bits/stdc++.h>
    string solve(string s, int left, int right) {
        int n = s.length();

        while (left >= 0 && right < n && s[left] == s[right]) {
            left--;
            right++;
        }

        return s.substr(left + 1, right - left - 1);
    }

    string longestPalindrome(string s) {
        int n = s.length();

        string ans = "";

        for (int i = 0; i < n; i++) {

            string odd = solve(s, i, i);
            if (odd.length() > ans.length())
                ans = odd;

            string even = solve(s, i, i + 1);
            if (even.length() > ans.length())
                ans = even;
        }

        return ans;
    
};
int main(){
string s;
cin>>s;
string ans=longestPalindrome(s);
cout<<ans;
}
