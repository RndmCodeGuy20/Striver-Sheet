//
// Created by SHANTANU on 18-06-2023.
//
#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    void uniqueSets(vector<int> &nums, int index, vector<int> &temp, vector<vector<int>> &rez) {
        if (index == nums.size()) {
            rez.push_back(temp);
            return;
        }

        temp.push_back(nums[index]);
        uniqueSets(nums, index + 1, temp, rez);
        temp.pop_back();

        while (index + 1 < nums.size() && nums[index] == nums[index + 1]) {
            index++;
        }

        uniqueSets(nums, index + 1, temp, rez);
    }

public:
    vector<vector<int>> uniqueSubsets(vector<int> &nums) {
        vector<vector<int>> rez;
        vector<int> temp;
        uniqueSets(nums, 0, temp, rez);

        return rez;
    }
};

int main() {

    vector<int> nums = {1, 1, 3};
    Solution solution;

    vector<vector<int>> rez = solution.uniqueSubsets(nums);

    sort(rez.begin(), rez.end());

    for (const vector<int> &i: rez) {
        for (int j: i) {
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}