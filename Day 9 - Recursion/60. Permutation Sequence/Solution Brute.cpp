#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    void generatePermutations(vector<int> &nums, vector<vector<int>> &result, int start) {
        if (start >= nums.size()) {
            result.push_back(nums);
            return;
        }
        for (int i = start; i < nums.size(); i++) {
            swap(nums[start], nums[i]);
            generatePermutations(nums, result, start + 1);
            swap(nums[start], nums[i]);
        }
    }

public:
    string getPermutation(int n, int k) {
        vector<int> nums;
        for (int i = 1; i <= n; i++) {
            nums.push_back(i);
        }
        vector<vector<int>> result;
        generatePermutations(nums, result, 0);
        string s;
        for (const auto &i: result[k - 1]) {
            s += to_string(i);
        }
        return s;
    }
};

int main() {

    Solution solution;

    cout << solution.getPermutation(3, 3) << endl;


    return 0;
}