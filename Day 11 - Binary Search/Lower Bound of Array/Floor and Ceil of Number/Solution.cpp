/**
 * Created by SHANTANU on 10-10-2023.
 * Topic - 
*/
#include <bits/stdc++.h>

using namespace std;

class Solution {
private:

public:
    pair<int, int> floorCeil(vector<int> nums, int target) {
        int high = nums.size() - 1, low = 0;
        int mid;
        pair<int, int> res;

        while (low <= high) {
            mid = (high + low) / 2;

            if (target <= nums[mid]) {
                res.second = nums[mid];
                high = mid - 1;
            } else {
                res.first = nums[mid];
                low = mid + 1;
            }
        }

        return res;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {10, 20, 30, 40, 50};
    int target = 21;

    pair<int, int> res = solution.floorCeil(nums, target);
    cout << res.first << " " << res.second;

    return 0;
}