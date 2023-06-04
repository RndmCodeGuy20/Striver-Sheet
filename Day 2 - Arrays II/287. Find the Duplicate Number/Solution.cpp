#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow, fast;
        slow = fast = nums[0];

        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
        }while(slow != fast);

        fast = nums[0];
        while (slow!=fast){
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }
};

int main(){
    Solution solution;
    vector<int> nums = {1,3,4,2,2};
    cout << solution.findDuplicate(nums);
}