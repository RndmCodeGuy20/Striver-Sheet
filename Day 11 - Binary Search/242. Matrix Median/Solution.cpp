//
// Created by SHANTANU on 27-06-2023.
//
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findMedian(vector<vector<int>> A, int rows, int cols) {
        vector<int> arr;

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                arr.push_back(A[i][j]);
            }
        }

        sort(arr.begin(), arr.end());

        return arr[(rows * cols) / 2];
    }
};

int main() {
    Solution solution;
    vector<vector<int>> A = {{1, 3, 5},
                             {2, 6, 9},
                             {3, 6, 9}};

    cout << solution.findMedian(A, 3, 3);


    return 0;
}