//
// Created by SHANTANU on 20-06-2023.
//
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

class Solution {
private:
    void sumSubsets(vector<int> &nums, int index, int target, vector<int> &temp, vector<vector<int>> &rez) {
        if (index == nums.size()) {
            if (target == 0) {
                rez.push_back(temp);
            };
            return;
        }

        if (nums[index] <= target) {
            temp.push_back(nums[index]);
            sumSubsets(nums, index, target - nums[index], temp, rez);
            temp.pop_back();
        }

        sumSubsets(nums, index + 1, target, temp, rez);
    }

public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        vector<vector<int>> rez;
        vector<int> temp;
        sumSubsets(candidates, 0, target, temp, rez);
        return rez;
    }
};

int main() {
    Solution solution;

    vector<int> candidates = {2, 3, 6, 7};

    vector<vector<int>> rez = solution.combinationSum(candidates, 7);

    for (auto &i: rez) {
        for (auto &j: i) {
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}