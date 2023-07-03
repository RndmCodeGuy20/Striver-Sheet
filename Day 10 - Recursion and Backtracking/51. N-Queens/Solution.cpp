//
// Created by SHANTANU on 25-06-2023.
//
#include <bits/stdc++.h>

using namespace std;

class Solution {

private:
    void
    solve(int col, vector<string> &board, vector<vector<string>> &rez, vector<int> &leftrow, vector<int> &upperDiag,
          vector<int> &lowerDiag, int n) {
        if (col == n) {
            rez.push_back(board);
            return;
        }

        for (int row = 0; row < n; row++) {
            if (leftrow[row] == 0 && upperDiag[row + col] == 0 && lowerDiag[n - 1 + col - row] == 0) {
                board[row][col] = 'Q';
                leftrow[row] = 1;
                upperDiag[row + col] = 1;
                lowerDiag[n - 1 + col - row] = 1;
                solve(col + 1, board, rez, leftrow, upperDiag, lowerDiag, n);
                board[row][col] = '.';
                leftrow[row] = 0;
                upperDiag[row + col] = 0;
                lowerDiag[n - 1 + col - row] = 0;
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> rez;
        vector<string> board(n, string(n, '.'));
        vector<int> leftrow(n, 0);
        vector<int> upperDiag(2 * n - 1, 0);
        vector<int> lowerDiag(2 * n - 1, 0);

        solve(0, board, rez, leftrow, upperDiag, lowerDiag, n);

        return rez;
    }
};

int main() {

    Solution solution;

    vector<vector<string>> res = solution.solveNQueens(4);

    for (auto i: res) {
        for (auto j: i) {
            cout << j << " ";
        }
        cout << endl;
    }


    return 0;
}