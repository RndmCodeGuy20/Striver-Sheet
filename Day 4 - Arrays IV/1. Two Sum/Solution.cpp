//
// Created by SHANTANU on 06-06-2023.
//
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        vector<int> rez = {0, 0};

        for (int i = 0; i < nums.size(); ++i) {
            rez[0] = nums[i];
            for (int j = i + 1; j < nums.size(); ++j) {
                rez[1] = nums[j];
                if (rez[0] == target - rez[1]) {
                    return rez;
                }
            }
        }

        return rez;
    }

    vector<int> twoSumMap(vector<int> &nums, int target) {
        vector<int> rez = {0, 0};
        unordered_map<int, int> map;

        for (int i = 0; i < nums.size(); ++i) {
            map[nums[i]] = i;
        }

        for (int i = 0; i < nums.size(); ++i) {
            int complement = target - nums[i];
            if (map.find(complement) != map.end() && map[complement] != i) {
                rez[0] = i;
                rez[1] = map[complement];
                return rez;
            }
        }

        return rez;
    }
};

int main() {

    Solution solution;
    vector<int> nums = {2, 7, 11, 15};
    vector<int> rez = solution.twoSum(nums, 9);

    for (int item: rez) {
        cout << item << " ";
    }

    return 0;
}