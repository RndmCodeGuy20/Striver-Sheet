//
// Created by SHANTANU on 25-06-2023.
//
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        int fact = 1;
        vector<int> nums;

        for (int i = 1; i <= n; i++) {
            fact *= i;
            nums.push_back(i);
        }

        k--;
        string rez;

        for (int i = 0; i < n; i++) {
            fact /= (n - i);
            int index = (k / fact);
            rez += to_string(nums[index]);
            nums.erase(nums.begin() + index);
            k -= index * fact;
        }

        return rez;
    }
};

int main() {
    Solution solution;

    cout << solution.getPermutation(3, 3) << endl;


    return 0;
}