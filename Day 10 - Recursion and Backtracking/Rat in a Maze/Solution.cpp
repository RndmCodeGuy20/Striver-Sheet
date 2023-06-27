//
// Created by SHANTANU on 25-06-2023.
//
#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    void solve(int row, int col, vector<vector<int>> &m, int n, string &path, vector<string> &rez) {
        if (row == n - 1 && col == n - 1) {
            rez.push_back(path);
            return;
        }

        if (row + 1 < n && m[row + 1][col] == 1) {
            path += 'D';
            solve(row + 1, col, m, n, path, rez);
            path.pop_back();
        }

        if (col + 1 < n && m[row][col + 1] == 1) {
            path += 'R';
            solve(row, col + 1, m, n, path, rez);
            path.pop_back();
        }
    }

public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> rez;
        string path;
        solve(0, 0, m, n, path, rez);
        return rez;
    }
};

int main() {

    Solution solution;

    vector<vector<int>> m = {{1, 0, 0, 0},
                             {1, 1, 0, 1},
                             {1, 1, 0, 0},
                             {0, 1, 1, 1}};

    vector<string> rez = solution.findPath(m, 4);

    for (const auto &i: rez) {
        cout << i << endl;
    }


    return 0;
}