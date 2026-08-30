#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool solve(vector<vector<char>> &board, int row, int col,
               string &word, int idx) {

        if (idx == word.size())
            return true;

        if (row < 0 || col < 0 || row >= board.size() ||
            col >= board[0].size() ||
            board[row][col] != word[idx])
            return false;

        char ch = board[row][col];
        board[row][col] = '#';   

        bool found =
            solve(board, row + 1, col, word, idx + 1) ||
            solve(board, row - 1, col, word, idx + 1) ||
            solve(board, row, col + 1, word, idx + 1) ||
            solve(board, row, col - 1, word, idx + 1);

        board[row][col] = ch;    // Backtrack

        return found;
    }

    bool exist(vector<vector<char>> &board, string word) {

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {

                if (solve(board, i, j, word, 0))
                    return true;
            }
        }

        return false;
    }
};

int main() {

    vector<vector<char>> board = {
        {'A','B','C','E'},
        {'S','F','C','S'},
        {'A','D','E','E'}
    };

    string word = "ABCCED";

    Solution obj;

    if (obj.exist(board, word))
        cout << "True";
    else
        cout << "False";

    return 0;
}