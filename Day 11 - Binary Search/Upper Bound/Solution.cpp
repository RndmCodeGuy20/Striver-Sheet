/**
 * Created by SHANTANU on 10-10-2023.
 * Topic - 
*/
#include <bits/stdc++.h>

using namespace std;

class Solution {
private:

public:
    int upperBound(vector<int> nums, int target) {
        int high = nums.size() - 1, low = 0;
        int mid, res;

        while (low <= high) {
            mid = (high + low) / 2;

            if (target <= nums[mid]) {
                res = nums[mid];
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return res;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 2, 3, 4, 6, 9, 13};
    int target = 5;

    cout << solution.upperBound(nums, target);

    return 0;
}