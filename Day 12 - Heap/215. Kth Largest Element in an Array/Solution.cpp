//
// Created by SHANTANU on 28-06-2023.
//
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int> &nums, int k) {
        priority_queue<int, vector<int>, greater<>> pq;

        for (int num: nums) {
            pq.push(num);
            if (pq.size() > k) pq.pop();
        }

        return pq.top();
    }
};

int main() {
    Solution solution;
    vector<int> nums = {3, 2, 1, 5, 6, 4};

    cout << solution.findKthLargest(nums, 2) << endl;

    return 0;
}