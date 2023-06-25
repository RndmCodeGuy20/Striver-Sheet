//
// Created by SHANTANU on 25-06-2023.
//
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int> &nums) {
//        int slow = nums[0];
//        int fast = nums[0];
//
//
//        while (fast < nums.size()) {
//            slow = nums[slow];
//            fast = nums[nums[fast]];
//
//            if (slow == fast) {
//                return true;
//            }
//        }
//
//        return false;

        unordered_set<int> set;
        for (int num: nums) {
            if (set.find(num) != set.end()) {
                return true;
            }

            set.insert(num);
        }
        return false;
    }
};

int main() {

    Solution solution;
    vector<int> nums = {1, 1, 1, 3, 3, 4, 3, 2, 4, 2};

    cout << solution.containsDuplicate(nums) << endl;


    return 0;
}