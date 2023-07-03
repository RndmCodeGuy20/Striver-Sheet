//
// Created by SHANTANU on 29-06-2023.
//
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int> &nums) {
        stack<int> stack;
        unordered_map<int, int> nge;

        for (int num: nums) {
            while (!stack.empty() && stack.top() >= num) {
                stack.pop();
            }
            if (stack.empty()) {
                nge[num] = -1;
                stack.push(num);
            } else {
                nge[num] = stack.top();
                stack.push(num);
            }
        }

        vector<int> rez;
        rez.reserve(nums.size());
        for (int item: nums) {
            rez.push_back(nge[item]);
        }

        return rez;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {3, 2, 1};

    vector<int> rez = solution.nextGreaterElement(nums);

    for (int item: rez) {
        cout << item << " ";
    }

    return 0;
}