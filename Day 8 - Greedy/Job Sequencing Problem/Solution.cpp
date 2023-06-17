//
// Created by SHANTANU on 17-06-2023.
//
#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    static bool comparator(vector<int> &a, vector<int> &b) {
        if (a[1] == b[1]) {
            return a[0] > b[0];
        }
        return a[1] > b[1];
    }

public:
    int jobScheduling(vector<vector<int>> &jobs) {
        int maxProfit = 0;
        int maxDeadline = 0;

        sort(jobs.begin(), jobs.end(), comparator);

        for (vector<int> dL: jobs) {
            maxDeadline = max(maxDeadline, dL[0]);
        }
        vector<int> timeline(maxDeadline + 1, -1);

        for (int i = 0; i < jobs.size(); ++i) {
            for (int j = maxDeadline; j > 0; j--) {
                if (timeline[j] == -1) {
                    timeline[j] = i;
                    maxProfit += jobs[i][1];
                    break;
                }
            }
        }

        return maxProfit;
    }
};

int main() {
    vector<vector<int>> jobs = {
            {2, 25},
            {4, 40},
            {1, 5},
            {3, 50},
            {5, 60},
    };

    Solution solution;

    cout << solution.jobScheduling(jobs);


    return 0;
}