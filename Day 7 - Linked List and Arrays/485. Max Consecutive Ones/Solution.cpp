//
// Created by SHANTANU on 15-06-2023.
//
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int> &nums) {
        int count = 0, maxCount = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) count++;
            else count = 0;

            maxCount = max(count, maxCount);
        }

        return maxCount;
    }
};

int main() {
    Solution solution;
    vector<int> arr = {1, 1, 0, 1, 1, 1};

    cout << solution.findMaxConsecutiveOnes(arr);

    return 0;
}