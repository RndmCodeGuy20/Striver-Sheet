//
// Created by SHANTANU on 08-07-2023.
//
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isSorted(vector<int> nums, int index) {
        if (index == 1) return nums[index - 1] < nums[index];

        return nums[index - 1] < nums[index] && isSorted(nums, index - 1);
    }
};

int main() {
    Solution solution;
    cout << solution.isSorted({1, 3, 2, 4, 5}, 4);

    return 0;
}