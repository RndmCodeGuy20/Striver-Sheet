//
// Created by SHANTANU on 18-06-2023.
//
#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    void subSum(vector<int> &nums, int sum, int index, vector<int> &rez) {
        if (index == nums.size()) {
            rez.push_back(sum);
            return;
        }

        subSum(nums, sum + nums[index], index + 1, rez);
        subSum(nums, sum, index + 1, rez);
    }

public:
    vector<int> subsetSum(vector<int> &nums) {
        vector<int> rez;
        subSum(nums, 0, 0, rez);

        return rez;
    }
};

int main() {
    vector<int> nums = {1, 2, 3};
    Solution solution;

    vector<int> rez = solution.subsetSum(nums);

    for (int i: rez) {
        cout << i << " ";
    }

    return 0;
}