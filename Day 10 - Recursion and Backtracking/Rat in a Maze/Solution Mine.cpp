//
// Created by SHANTANU on 01-07-2023.
//
#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    void solveMaze(int row, int col, vector<vector<int>> maze, vector<string> &rez,
                   string path, int n, vector<vector<bool>> visited) {
        if (row == n - 1 && col == n - 1) {
            rez.push_back(path);
            return;
        }

        if (col + 1 < n && maze[row][col + 1] == 1 && !visited[row][col + 1]) {
            path += "R";
            visited[row][col] = true;
            solveMaze(row, col + 1, maze, rez, path, n, visited);
            path.pop_back();
            visited[row][col] = false;
        }

        if (col - 1 >= 0 && maze[row][col - 1] == 1 && !visited[row][col - 1]) {
            path += "L";
            visited[row][col] = true;
            solveMaze(row, col - 1, maze, rez, path, n, visited);
            path.pop_back();
            visited[row][col] = false;
        }

        if (row + 1 < n && maze[row + 1][col] == 1 && !visited[row + 1][col]) {
            path += "D";
            visited[row][col] = true;
            solveMaze(row + 1, col, maze, rez, path, n, visited);
            path.pop_back();
            visited[row][col] = false;
        }

        if (row - 1 >= 0 && maze[row - 1][col] == 1 && !visited[row - 1][col]) {
            path += "U";
            visited[row][col] = true;
            solveMaze(row - 1, col, maze, rez, path, n, visited);
            path.pop_back();
            visited[row][col] = false;
        }
    }

public:
    vector<string> mazePaths(vector<vector<int>> &maze, int n) {
        vector <string> rez;
        string path;
        vector <vector<bool>> visited(n, vector<bool>(n, false));
        solveMaze(0, 0, maze, rez, path, n, visited);
        return rez;
    }
};

int main() {
    Solution solution;

    vector<vector<int>> m = {{1, 1},
                             {1, 0}};

    vector<string> rez = solution.mazePaths(m, 2);

    for (const auto &i: rez) {
        cout << i << endl;
    }

    return 0;
}