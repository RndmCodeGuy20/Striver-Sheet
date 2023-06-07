//
// Created by SHANTANU on 07-06-2023.
//
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool linSearch(vector<int> nums, int target) {
        for (int item: nums) {
            if (item == target) {
                return true;
            }
        }

        return false;
    }

    int longestConsecutive(vector<int> &nums) {
        int count = 1;

        for (int i = 0; i < nums.size(); ++i) {
            int temp = 1;
            int x = nums[i];
            while (linSearch(nums, x + 1)) {
                x++;
                temp++;
            }
            count = max(count, temp);
        }

        return count;
    }
};

int main() {
    vector<int> nums = {100, 4, 200, 1, 3};

    Solution solution;
    cout << solution.longestConsecutive(nums);

    return 0;
}