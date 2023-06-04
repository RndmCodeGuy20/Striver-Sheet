//
// Created by SHANTANU on 02-06-2023.
//
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    static void rotate(vector<vector<int>> &matrix) {
        int n = matrix.size();

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

//        for (int i = 0; i < n; ++i) {
//            reverse(matrix[i].begin(), matrix[i].end());
//        }
        for (auto &item: matrix) {
            reverse(item.begin(), item.end());
            cout << item[0] << " ";
        }

        cout << endl;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Solution solution;
    vector<vector<int>> matrix = {{1, 2, 3},
                                  {4, 5, 6},
                                  {7, 8, 9}};

    solution.rotate(matrix);

    return 0;
}