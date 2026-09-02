#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool istrue(vector<vector<char>>& board, int row, int col, char val) {
        for (int b = 0; b < 9; b++) {
            if (board[b][col] == val) return false;
        }

        for (int b = 0; b < 9; b++) {
            if (board[row][b] == val) return false;
        }

        int sttrow = (row / 3) * 3;
        int sttcol = (col / 3) * 3;

        for (int b = sttrow; b < sttrow + 3; b++) {
            for (int c = sttcol; c < sttcol + 3; c++) {
                if (board[b][c] == val) return false;
            }
        }

        return true;
    }

    bool solve(vector<vector<char>>& board, int row, int col) {
        int n = board.size();
        int m = board[0].size();

        if (row == n) {
            return true;
        }

        if (row < 0 || col < 0 || row >= n || col >= m) {
            return false;
        }

        int nextRow = row;
        int nextCol = col + 1;

        if (nextCol == 9) {
            nextRow++;
            nextCol = 0;
        }

        if (board[row][col] != '.')
            return solve(board, nextRow, nextCol);

        for (char b = '1'; b <= '9'; b++) {
            if (istrue(board, row, col, b)) {
                board[row][col] = b;

                if (solve(board, nextRow, nextCol))
                    return true;

                board[row][col] = '.';
            }
        }

        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(board, 0, 0);
    }
};

int main() {
    vector<vector<char>> board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };

    Solution obj;
    obj.solveSudoku(board);

    for (auto &row : board) {
        for (char x : row)
            cout << x << " ";
        cout << endl;
    }

    return 0;
}