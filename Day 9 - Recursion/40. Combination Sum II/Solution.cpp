//
// Created by SHANTANU on 20-06-2023.
//
#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    void sumSubsets(vector<int> &nums, int index, int target, vector<int> &temp, vector<vector<int>> &rez) {
        if (target == 0) {
            rez.push_back(temp);
        }

        for (int i = index; i < nums.size(); ++i) {
            if (i > index && nums[i] == nums[i - 1]) {
                continue;
            }

            if (nums[i] <= target) {
                temp.push_back(nums[i]);
                sumSubsets(nums, i + 1, target - nums[i], temp, rez);
                temp.pop_back();
            }
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
        vector<vector<int>> rez;
        vector<int> temp;
        sumSubsets(candidates, 0, target, temp, rez);
        return rez;
    }
};

int main() {
    Solution solution;

    vector<int> candidates = {10, 1, 2, 7, 6, 1, 5};

    sort(candidates.begin(), candidates.end());

    vector<vector<int>> rez = solution.combinationSum2(candidates, 8);

    for (auto &i: rez) {
        for (auto &j: i) {
            cout << j << " ";
        }
        cout << endl;
    }


    return 0;
}