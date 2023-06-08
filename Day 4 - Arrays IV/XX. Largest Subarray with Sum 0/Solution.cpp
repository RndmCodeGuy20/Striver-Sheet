//
// Created by SHANTANU on 08-06-2023.
//
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int LongestSubsetWithZeroSum(vector<int> arr) {
        map<int, int> map;
        int maxCount = 0, count = 0, sum = 0;

        for (int i = 0; i < arr.size(); ++i) {
            sum += arr[i];
            if (sum == 0) {
                maxCount = i + 1;
            } else {
                if (map.find(sum) != map.end()) {
                    maxCount = max(maxCount, i - map[sum]);
                } else {
                    map[sum] = i;
                }
            }
        }
        return maxCount;
    }
};

int main() {
    Solution solution;
    vector<int> arr = {1, -1, 3, 2, -2, -8, 1, 7, 10, 23};
    cout << solution.LongestSubsetWithZeroSum(arr);


    return 0;
}