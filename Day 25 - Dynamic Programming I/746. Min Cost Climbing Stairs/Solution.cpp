/**
 * Created by SHANTANU on 20-07-2023.
 * Topic - Dynamic Programming
*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    int minCost(int index, vector<int> &dp, vector<int> &cost) {
        if (index == 0 || index == 1) {
            return cost[index];
        }
        if (index < 0) return 0;
        if (dp[index] != -1) return dp[index];
        dp[index] = min(minCost(index - 1, dp, cost), minCost(index - 2, dp, cost)) + cost[index];
        return dp[index];
    }

public:
    int minCostClimbingStairs(vector<int> &cost) {
        vector<int> dp(cost.size() + 1, -1);
        return min(minCost((uint8_t) cost.size() - 1, dp, cost), minCost((uint8_t) cost.size() - 2, dp, cost));
    }
};

int main() {
    Solution solution;
    vector<int> cost = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};

    cout << solution.minCostClimbingStairs(cost);
    return 0;
}
