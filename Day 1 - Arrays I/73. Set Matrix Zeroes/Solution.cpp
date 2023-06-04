//
// Created by SHANTANU on 31-05-2023.
//
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>> &matrix) {
        vector<pair<int, int>> zeroes;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if (matrix[i][j] == 0) {
                    zeroes.emplace_back(i, j);
                }
            }
        }

        for (pair<int, int> item: zeroes) {
            for (int k = 0; k < matrix[0].size(); k++) {
                matrix[item.first][k] = 0;
            }
            for (int k = 0; k < matrix.size(); k++) {
                matrix[k][item.second] = 0;
            }
        }

        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                printf("%d ", matrix[i][j]);
            }
            cout << endl;
        }
    }
};

int main() {

    vector<vector<int>> matrix = {{0, 1, 2, 0},
                                  {3, 4, 5, 2},
                                  {1, 3, 1, 5}};

    Solution solution;
    solution.setZeroes(matrix);


    return 0;
}