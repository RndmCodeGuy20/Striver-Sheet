//
// Created by SHANTANU on 29-06-2023.
//
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2) {
        stack<int> stack;
        unordered_map<int, int> nge;

        for (int i = nums2.size() - 1; i >= 0; --i) {
            while (!stack.empty() && stack.top() <= nums2[i]) {
                stack.pop();
            }
            if (stack.empty()) {
                nge[nums2[i]] = -1;
                stack.push(nums2[i]);
            } else {
                nge[nums2[i]] = stack.top();
                stack.push(nums2[i]);
            }
        }

        vector<int> rez;
        rez.reserve(nums1.size());
        for (int item: nums1) {
            rez.push_back(nge[item]);
        }

        return rez;
    }
};

int main() {
    Solution solution;
    vector<int> nums1 = {2, 4};
    vector<int> nums2 = {1, 2, 3, 4};

    vector<int> rez = solution.nextGreaterElement(nums1, nums2);

    for (int item: rez) {
        cout << item << " ";
    }

    return 0;
}