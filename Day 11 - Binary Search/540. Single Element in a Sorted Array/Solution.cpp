//
// Created by SHANTANU on 27-06-2023.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int> &nums) {
        int low = 0, high = nums.size() - 1, mid;

        while (low < high) {
            mid = (low + high) / 2;

            if (nums[mid] == nums[mid ^ 1]) low = mid + 1;
            else high = mid - 1;
        }

        return nums[low];
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 1, 2, 3, 3, 4, 4, 8, 8};

    cout << solution.singleNonDuplicate(nums) << endl;
     
    return 0;
}