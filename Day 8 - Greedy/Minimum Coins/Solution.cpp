//
// Created by SHANTANU on 17-06-2023.
//
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findMinimumCoins(int amount) {
        int coins[] = {1, 2, 5, 10, 20, 50, 100, 500, 1000};
        int n = sizeof(coins) / sizeof(coins[0]);
        int answer = 0;
        for (int i = n - 1; i >= 0; i--) {
            while (amount >= coins[i]) {
                amount -= coins[i];
                answer++;
            }
        }
        return answer;
    }
};

int main() {
    int amount = 60;

    Solution solution;

    cout << solution.findMinimumCoins(amount);

    return 0;
}