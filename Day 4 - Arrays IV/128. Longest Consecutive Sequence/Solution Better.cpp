//
// Created by SHANTANU on 07-06-2023.
//
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    static int longestConsecutive(vector<int> &nums) {
        std::sort(nums.begin(), nums.end());
        int count = 1;
        int prevSmaller = INT_MIN;
        int temp = 1;
        for (int num: nums) {
            if (num == prevSmaller + 1) {
                prevSmaller++;
                temp++;
            } else if (num != prevSmaller) {
                prevSmaller = num;
                temp = 1;
            }
            count = max(count, temp);
        }

        return count;
    }
};

int main() {
    vector<int> nums = {1, 1, 1, 2, 2, 3, 4, 100, 101, 102, 103, 104};
    cout << Solution::longestConsecutive(nums);


    return 0;
}