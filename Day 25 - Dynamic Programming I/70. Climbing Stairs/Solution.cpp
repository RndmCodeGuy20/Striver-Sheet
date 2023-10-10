#include <bits/stdc++.h>

using namespace std;

class Solution {
private:


public:
    int climbStairs(int n) {
        vector<int> dp(n + 1, -1);
        dp[0] = dp[1] = 1;

        for (int i = 2; i < n + 1; ++i) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        return dp[n];
    }
};

int main() {
    Solution solution;
    cout << solution.climbStairs(3);

    return 0;
}