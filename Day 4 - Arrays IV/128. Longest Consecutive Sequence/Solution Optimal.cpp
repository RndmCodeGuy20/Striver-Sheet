//
// Created by SHANTANU on 07-06-2023.
//
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int> &nums) {
        int count = 1;
        unsigned int n = nums.size();
        if (n == 0) return 0;

        int temp = 0;
        unordered_set<int> set;

        for (int i = 0; i < n; ++i) {
            set.insert(nums[i]);
        }

        for (int item: set) {
            if (set.find(item - 1) == set.end()) {
                temp = 1;
                int x = item;

                while (set.find(x + 1) != set.end()) {
                    x = x + 1;
                    temp++;
                }

                count = max(count, temp);
            }
        }
        return count;
    }
};

int main() {
    vector<int> nums = {1, 1, 1, 2, 2, 3, 4, 100, 101, 102, 103, 104};
    Solution solution;
    cout << solution.longestConsecutive(nums);

    return 0;
}