//
// Created by SHANTANU on 04-06-2023.
//
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int minimum = prices[0], maxProfit = 0;

        for (int price: prices) {
            int cost = price - minimum;
            minimum = min(minimum, price);
            maxProfit = max(maxProfit, cost);
        }

        return maxProfit;
    }
};

int main() {
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    Solution solution;

    cout << solution.maxProfit(prices);

    return 0;
}