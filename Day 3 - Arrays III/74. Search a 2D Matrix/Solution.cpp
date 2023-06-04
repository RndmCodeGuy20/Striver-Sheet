//
// Created by SHANTANU on 03-06-2023.
//
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        unsigned int m = matrix.size(), n = matrix[0].size();
        unsigned int left = 0;
        unsigned int right = m * n - 1;
        unsigned int mid = (left + right) / 2;

        while (left <= right) {
            mid = (left + right) / 2;
            if (target == matrix[mid / n][mid % n]) {
                return true;
            } else if (target > matrix[mid / n][mid % n]) {
                left = mid + 1;
            } else if (target < matrix[mid / n][mid % n]) {
                right = mid - 1;
            }
        }
        return false;
    }

};

int main() {
    vector<vector<int>> matrix = {{1,  3,  5,  7},
                                  {10, 11, 16, 20},
                                  {23, 30, 34, 60}};

//    int m = matrix.size(), n = matrix[0].size();

//    cout << matrix[4 / n][4 % n];

    Solution solution;
    cout << solution.searchMatrix(matrix, 12);

    return 0;
}