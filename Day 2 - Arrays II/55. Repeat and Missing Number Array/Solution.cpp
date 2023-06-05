//
// Created by SHANTANU on 05-06-2023.
//
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> repeatedNumber(vector<int> &nums) {
        int n = nums.size();
        int SN = (n * (n + 1)) / 2;
        int SSN = (n * (n + 1) * (2 * n + 1)) / 6;

        int S = 0, SS = 0;
        for (int i = 0; i < n; ++i) {
            S += nums[i];
            SS += nums[i] * nums[i];
        }

        cout << SN << " " << SSN << endl;

        vector<int> rez = {0, 0};

        rez[0] = ((S - SN) + (SS - SSN) / (S - SN)) / 2;
        cout << rez[0] << endl;
        rez[1] = rez[0] - (S - SN);

        return rez;
    }
};

int main() {

    Solution solution;
    vector<int> nums = {1, 2, 3, 3, 5};
    vector<int> rez = solution.repeatedNumber(nums);

    for (int item: rez) {
        cout << item << " ";
    }


    return 0;
}