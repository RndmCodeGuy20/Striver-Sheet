//
// Created by SHANTANU on 25-06-2023.
//
#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    void generateSubsets(int index, vector<int> &nums, vector<int> &subset, vector<vector<int>> &rez) {
        if (index == nums.size()) {
            rez.push_back(subset);
            return;
        }

        subset.push_back(nums[index]);
        generateSubsets(index + 1, nums, subset, rez);
        subset.pop_back();
        generateSubsets(index + 1, nums, subset, rez);
    }

public:
    vector<vector<int>> subsets(vector<int> &nums) {
        vector<vector<int>> rez;
        vector<int> subset;

        generateSubsets(0, nums, subset, rez);

        return rez;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 2, 3};

    vector<vector<int>> rez = solution.subsets(nums);

    for (auto i: rez) {
        for (auto j: i) {
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}