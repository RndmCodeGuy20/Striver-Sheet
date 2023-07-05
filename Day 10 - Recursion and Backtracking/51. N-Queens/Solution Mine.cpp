//
// Created by SHANTANU on 01-07-2023.
//
#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    void solve(
            int col,
            vector<string> board,
            vector<vector<string>> &rez,
            vector<bool> row,
            vector<bool> leftDiag,
            vector<bool> rightDiag,
            int n
    ) {
        if (col == n) {
            rez.push_back(board);
            return;
        }

//        for (const auto &j: board) {
//            cout << j << " ";
//        }
//        cout << endl;
        for (int r = 0; r < n; ++r) {
            if (row[r] || leftDiag[r - col + (n - 1)] || rightDiag[r + col]) continue;

            row[r] = true;
            leftDiag[r - col + (n - 1)] = true;
            rightDiag[r + col] = true;
            board[r][col] = 'Q';

            solve(col + 1, board, rez, row, leftDiag, rightDiag, n);

            row[r] = false;
            leftDiag[r - col + (n - 1)] = false;
            rightDiag[r + col] = false;
            board[r][col] = '.';
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        vector<vector<string>> rez;

        vector<bool> row(1 * n, false);
        vector<bool> leftDiag(2 * n - 1, false);
        vector<bool> rightDiag(2 * n - 1, false);

        solve(0, board, rez, row, leftDiag, rightDiag, n);

        return rez;
    }
};

int main() {
    Solution solution;
    vector<vector<string>> rez = solution.solveNQueens(8);

    for (const auto &i: rez) {
        for (const auto &j: i) {
            cout << j << endl;
        }
        cout << endl;
    }

    cout << rez.size() << endl;

    return 0;
}