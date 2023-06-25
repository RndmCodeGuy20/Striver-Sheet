//
// Created by SHANTANU on 23-06-2023.
//
#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    void genPerm(vector<int> &nums, vector<bool> freq, vector<int> &temp, vector<vector<int>> &rez) {
        if (temp.size() == nums.size()) {
            rez.push_back(temp);
            return;
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (!freq[i]) {
                freq[i] = true;
                temp.push_back(nums[i]);
                genPerm(nums, freq, temp, rez);
                temp.pop_back();
                freq[i] = false;
            }
        }
    }

public:
    vector<vector<int>> permute(vector<int> &nums) {
        vector<vector<int>> rez;
        vector<int> temp;
        vector<bool> freq(nums.size(), false);
        genPerm(nums, freq, temp, rez);
        return rez;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 2, 3};

    vector<vector<int>> rez = solution.permute(nums);

    for (auto &i: rez) {
        for (int j: i) {
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}