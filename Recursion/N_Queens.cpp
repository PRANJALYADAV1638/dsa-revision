#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solve(int row, int n, vector<string> &board,
               vector<vector<string>> &ans,
               vector<int> &col,
               vector<int> &upperDiagonal,
               vector<int> &lowerDiagonal) {

        if (row == n) {
            ans.push_back(board);
            return;
        }

        for (int j = 0; j < n; j++) {

            if (col[j] == 0 &&
                lowerDiagonal[row + j] == 0 &&
                upperDiagonal[n - 1 + j - row] == 0) {

                board[row][j] = 'Q';

                col[j] = 1;
                lowerDiagonal[row + j] = 1;
                upperDiagonal[n - 1 + j - row] = 1;

                solve(row + 1, n, board, ans,
                      col, upperDiagonal, lowerDiagonal);

                board[row][j] = '.';

                col[j] = 0;
                lowerDiagonal[row + j] = 0;
                upperDiagonal[n - 1 + j - row] = 0;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {

        vector<vector<string>> ans;

        vector<string> board(n, string(n, '.'));

        vector<int> col(n, 0);
        vector<int> upperDiagonal(2 * n - 1, 0);
        vector<int> lowerDiagonal(2 * n - 1, 0);

        solve(0, n, board, ans, col, upperDiagonal, lowerDiagonal);

        return ans;
    }
};

int main() {

    int n = 4;

    Solution obj;

    vector<vector<string>> ans = obj.solveNQueens(n);

    for (auto board : ans) {
        for (auto row : board)
            cout << row << endl;
        cout << endl;
    }

    return 0;
}