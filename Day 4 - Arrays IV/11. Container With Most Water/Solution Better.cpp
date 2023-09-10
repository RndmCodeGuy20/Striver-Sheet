//
// Created by SHANTANU on 10-07-2023.
//
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxArea(vector<int> &height) {
        int maxAr = INT_MIN;
        int left = 0, right = height.size() - 1;
        while (left < right) {
            maxAr = max(maxAr, min(height[left], height[right]) * (right - left));
            if (height[left] < height[right]) left++;
            else right--;
        }
        return maxAr;
    }
};

int main() {
    Solution solution;
    vector<int> height = {1, 1};
    cout << solution.maxArea(height);
    return 0;
}