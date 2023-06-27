//
// Created by SHANTANU on 27-06-2023.
//
#include <bits/stdc++.h>
#include <iostream>


using namespace std;

class Solution {
public:
    int search(vector<int> &nums, int target) {
        int low = 0, high = nums.size() - 1, mid;

        while (low <= high) {
            mid = (low + high) / 2;

            if (nums[mid] == target) return mid;

            if (nums[low] <= nums[mid]) {
                if (target >= nums[low] && target <= nums[mid]) high = mid - 1;
                else low = mid + 1;
            } else {
                if (target >= nums[mid] && target <= nums[high]) low = mid + 1;
                else high = mid - 1;
            }
        }

        return -1;
    }
};

int main() {

    Solution solution;

    vector<int> nums = {5, 6, 7, 1, 2, 3, 4};
    cout << solution.search(nums, 1);


    return 0;
}