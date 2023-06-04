//
// Created by SHANTANU on 02-06-2023.
//
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals) {
        sort(intervals.begin(), intervals.end());
        int n = intervals.size();

        vector<vector<int>> res;
        for (int i = 0; i < n; ++i) {
            if (res.empty() || (res.back()[1] <= intervals[i][0])) {
                res.push_back(intervals[i]);
            } else {
                res.back()[1] = max(res.back()[1], intervals[i][1]);
            }
        }

        return res;
    }
};

int main() {
    vector<vector<int>> intervals = {
            {1,  3},
            {2,  6},
            {8,  10},
            {15, 18}
    };
    Solution solution;
    vector<vector<int>> ans = solution.merge(intervals);

    for (auto item: ans) {
        for (auto j: item) {
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}