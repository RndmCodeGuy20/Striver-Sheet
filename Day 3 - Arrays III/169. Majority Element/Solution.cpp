#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 1;
        int el = nums[0];

        for(int i = 1; i < nums.size(); i++){
            if(count == 0){
                el = nums[i];
            }
            if(el == nums[i]){
                count++;
            }
            else if(el != nums[i]){
                count--;
            }
        }

        return el;
    }
};

int main(){
    Solution solution;
    vector<int> nums = {2,2,1,1,1,2,2};
    cout << solution.majorityElement(nums);
}