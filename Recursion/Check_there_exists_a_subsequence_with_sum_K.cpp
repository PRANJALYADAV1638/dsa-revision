#include <bits/stdc++.h>
using namespace std;

bool solve(vector<int> &arr, int target, int idx) {
    if (target == 0)
        return true;

    if (idx == arr.size() || target < 0)
        return false;

    if (solve(arr, target - arr[idx], idx + 1))
        return true;

    return solve(arr, target, idx + 1);
}

int main() {
    vector<int> arr = {4, 9, 2, 5, 1};

    int target;
    cin >> target;

    if (solve(arr, target, 0))
        cout << "YES\n";
    else
        cout << "NO\n";
}