//
// Created by SHANTANU on 02-06-2023.
//
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {

        int left = m - 1;
        int right = 0;


        while (left >= 0 && right < n) {
            if (nums1[left] > nums2[right]) {
                cout << nums1[left] << " " << nums2[right] << endl;
                swap(nums1[left], nums2[right]);
                left--, right++;

            } else {
                break;
            }
        }

        sort(nums2.begin(), nums2.end());
        sort(nums1.begin(), nums1.end());

        for (int i = 0; i < m; ++i) {
            cout << nums1[m] << " ";
        }
        for (int i = 0; i < n; ++i) {
            cout << nums2[n] << " ";
        }
    }
};

int main() {

    vector<int> nums1 = {1, 3, 5, 7};
    vector<int> nums2 = {0, 2, 4, 6, 8};

    Solution solution;
    solution.merge(nums1, nums1.size(), nums2, nums2.size());


    return 0;
}