//
// Created by SHANTANU on 02-06-2023.
//
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
        int ptr = m + n - 1;
        int high1 = m - 1;
        int high2 = n - 1;

        while (high1 > 0 && high2 >= 0) {
            if (nums1[high1] >= nums2[high2]) {
                nums1[ptr] = nums1[high1];
                high1--;
                ptr--;
            } else {
                nums1[ptr] = nums2[high2];
                high2--;
                ptr--;
            }
        }

        while (high2 >= 0) {
            nums1[ptr] = nums2[high2];
            high2--;
            ptr--;
        }


//        if (ptr == high2) {
//            nums1[ptr] = nums2[ptr];
//        }

        for (int item: nums1) {
            cout << item << " ";
        }
    }
};

int main() {

    vector<int> nums1 = {2, 0};
    vector<int> nums2 = {1};

    Solution solution;
    solution.merge(nums1, 1, nums2, 1);


    return 0;
}