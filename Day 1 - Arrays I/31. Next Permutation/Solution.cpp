#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int> &nums) {
        int n = nums.size();
        int inflectionPoint = n - 2;
        int next = n - 1;

        while (inflectionPoint >= 0 && nums[inflectionPoint] >= nums[inflectionPoint + 1]) inflectionPoint--;

        if (inflectionPoint >= 0) {
            while (nums[next] < nums[inflectionPoint]) next--;
            swap(nums[next], nums[inflectionPoint]);
        }

        reverse(nums.begin() + inflectionPoint + 1, nums.end());

        for (int item: nums) {
            cout << item << " ";
        }
    }
};

int main() {
    Solution solution;
    vector<int> nums = {5, 1, 3, 4, 2};
    solution.nextPermutation(nums);
}