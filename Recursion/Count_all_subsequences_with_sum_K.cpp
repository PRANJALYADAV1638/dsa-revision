#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> &arr, int target, int idx,
           vector<int> &curr, vector<vector<int>> &ans) {

    if (target == 0) {
        ans.push_back(curr);
        return;
    }

    if (idx == arr.size() || target < 0)
        return;

    curr.push_back(arr[idx]);
    solve(arr, target - arr[idx], idx + 1, curr, ans);
    curr.pop_back();

    solve(arr, target, idx + 1, curr, ans);
}

int main() {
    vector<int> arr = {4, 9, 2, 5, 1};

    int target;
    cin >> target;

    vector<vector<int>> ans;
    vector<int> curr;

    solve(arr, target, 0, curr, ans);

    for (auto final : ans) {
        for (auto x : final)
            cout << x << " ";
        cout << "\n";
    }
}