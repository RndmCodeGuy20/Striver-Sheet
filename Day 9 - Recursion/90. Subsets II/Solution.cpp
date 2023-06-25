//
// Created by SHANTANU on 25-06-2023.
//
#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    void generateUniqueSubsets(int index, vector<int> nums, vector<int> &temp, vector<vector<int>> &rez) {
        if (index == nums.size()) {
            rez.push_back(temp);
            return;
        }

        temp.push_back(nums[index]);
        generateUniqueSubsets(index + 1, nums, temp, rez);
        temp.pop_back();

        while (index + 1 < nums.size() && nums[index] == nums[index + 1]) index++;

        generateUniqueSubsets(index + 1, nums, temp, rez);
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums) {
        vector<vector<int>> rez;
        vector<int> temp;

        sort(nums.begin(), nums.end());

        generateUniqueSubsets(0, nums, temp, rez);

        return rez;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 2, 2};
    vector<vector<int>> rez = solution.subsetsWithDup(nums);

    for (auto i: rez) {
        for (auto j: i) {
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}