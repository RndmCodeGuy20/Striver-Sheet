//
// Created by SHANTANU on 27-06-2023.
//
#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    int countNums(vector<int> &rows, int mid) {
        uint8_t l = 0, h = rows.size() - 1;

        while (l <= h) {
            int m = (l + h) / 2;
            if (rows[m] <= mid) {
                l = m + 1;
            } else {
                h = m - 1;
            }
        }

        return l;
    }

public:
    int findMedian(vector<vector<int>> &matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        int low = 1, high = 1e9, mid;

        while (low <= high) {
            mid = (low + high) / 2;
            int count = 0;
            for (int i = 0; i < rows; ++i) {
                count += this->countNums(matrix[i], mid);
            }
            if (count <= (rows * cols) / 2) low = mid + 1;
            else high = mid - 1;
        }
        return low;
    }
};

int main() {
    Solution solution;
    vector<vector<int>> A = {{1, 3, 5},
                             {2, 6, 9},
                             {3, 6, 9}};

    cout << solution.findMedian(A);


    return 0;
}