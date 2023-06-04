#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxSubArray(vector<int>& nums) {
        long long maxSum = INT_MIN;
        long long sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            cout << sum << " ";
            sum += nums[i];
            maxSum = max(maxSum, sum);
            if (sum < 0) sum = 0;
        }
        return maxSum;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {-7, -8, -16, -4 ,-8, -5, -7, -11, -10, -12, -4, -6, -4, -16, -10 };
    cout << solution.maxSubArray(nums) << endl;
    return 0;
}