/**
 * Created by SHANTANU on 20-07-2023.
 * Topic - Dynamic Programming
*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    int maxRob(int index, vector<int> nums) {
        if (index >= nums.size()) {
            return 0;
        }

        for (int i = 2; i < nums.size(); ++i) {
            int rob = maxRob(index + i, nums);
        }

        
    }

public:
    int rob(vector<int> &nums) {
        return max(maxRob(0, nums), maxRob(1, nums));
    }
};

int main() {
    Solution solution;
    vector<int> nums = {2, 7, 9, 3, 1};
    cout << solution.rob(nums);

    return 0;
}