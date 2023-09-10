//
// Created by SHANTANU on 10-07-2023.
//
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxArea(vector<int> &height) {
        int maxAr = INT_MIN;
        for (int i = 0; i < height.size(); ++i) {
            int temp = 0;
            for (int j = i; j < height.size(); ++j) {
                temp = max(min(height[i], height[j]) * (j - i), temp);
            }
            maxAr = max(maxAr, temp);
        }
        return maxAr;
    }
};

int main() {
    Solution solution;
    vector<int> height = {2, 3, 4, 5, 18, 17, 6};
    cout << solution.maxArea(height);

    return 0;
}