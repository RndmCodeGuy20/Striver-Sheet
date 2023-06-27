//
// Created by SHANTANU on 27-06-2023.
//
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
//        int low = 0, high = nums1.size(), l1, l2, r1, r2;
//
//        while (low <= high) {
//            r1 = (low + high) / 2;
//            r2 = ((nums1.size() + nums2.size()) / 2) - r1;
//
//            if (nums1[r1 - 1] <= nums2[r2] and nums2[r2 - 1] <= nums1[r1]) {
//                return nums1.size() + nums2.size() % 2 ==
//                       0 ? (max(nums1[r1 - 1], nums2[r2 - 1]) + min(nums1[r1], nums2[r2]) / 2.0) : max(nums1[r1 - 1],
//                                                                                                       nums2[r2 - 1]);
//            } else if (nums1[r1 - 1] >= nums2[r2]) high = r1 - 1;
//            else if (nums2[r2 - 1] >= nums1[r1]) low = r1 + 1;
//        }

        if (nums1.size() > nums2.size()) return findMedianSortedArrays(nums2, nums1);

        int x = nums1.size(), y = nums2.size();
        int low = 0, high = x;

        while (low <= high) {
            int cut1 = (low + high) / 2;
            int cut2 = (x + y + 1) / 2 - cut1;

            int l1 = cut1 == 0 ? INT_MIN : nums1[cut1 - 1];
            int l2 = cut2 == 0 ? INT_MIN : nums2[cut2 - 1];

            int r1 = cut1 == x ? INT_MAX : nums1[cut1];
            int r2 = cut2 == y ? INT_MAX : nums2[cut2];

            if (l1 <= r2 and l2 <= r1) {
                if ((x + y) % 2 == 0) {
                    return (max(l1, l2) + min(r1, r2)) / 2.0;
                } else {
                    return max(l1, l2);
                }
            } else if (l1 > r2) {
                high = cut1 - 1;
            } else {
                low = cut1 + 1;
            }
        }

        return 0.0;
    }
};

int main() {
    Solution solution;
    vector<int> nums1 = {1, 2}, nums2 = {3, 4};

    cout << solution.findMedianSortedArrays(nums1, nums2);


    return 0;
}