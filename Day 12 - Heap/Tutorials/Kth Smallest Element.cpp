//
// Created by SHANTANU on 07-07-2023.
//
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int kthSmallest(int arr[], int l, int r, int k) {
        priority_queue<int> PQ;

        for (int i = 0; i < k; ++i) {
            PQ.push(arr[i]);
        }

        for (int i = k; i <= r; ++i) {
            if (arr[i] < PQ.top()) {
                PQ.pop();
                PQ.push(arr[i]);
            }
        }

        return PQ.top();
    }
};

int main() {
    Solution solution;
    int nums[] = {7, 10, 4, 3, 20, 15};
    cout << solution.kthSmallest(nums, 0, 5, 3);

    return 0;
}