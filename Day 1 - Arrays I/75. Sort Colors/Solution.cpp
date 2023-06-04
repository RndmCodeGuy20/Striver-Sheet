#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void sortColors(vector<int> &nums) {
        int low = 0, mid = 0, high = nums.size() - 1;
        while (mid <= high) {
            if (nums[mid] == 0) {
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            } else if (nums[mid] == 1) {
                mid++;
            } else {
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }

    void SortColorsDNF(vector<int> &nums) {
        int low = 0, mid = 0, high = nums.size() - 1;

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[mid] == 0) {
                swap(nums[mid], nums[low]);
                low++;
                mid++;
            } else if (nums[mid] == 1) {
                mid++;
            } else {
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};

int main() {
    Solution solution;
    vector<int> nums = {2, 0};
//    solution.sortColors(nums);
    solution.SortColorsDNF(nums);
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
    return 0;
}