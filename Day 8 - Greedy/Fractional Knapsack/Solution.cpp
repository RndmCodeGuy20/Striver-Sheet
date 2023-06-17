//
// Created by SHANTANU on 17-06-2023.
//
#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    static bool comparator(pair<int, int> &a, pair<int, int> &b) {
        double r1 = (double) a.second / (double) a.first;
        double r2 = (double) b.second / (double) b.first;
        return r1 > r2;
    }

public:
    double maximumValue(vector<pair<int, int>> &items, int n, int w) {
        double maxVal = 0.0;

        sort(items.begin(), items.end(), comparator);

        for (int i = 0; i < n; ++i) {
            if (items[i].first <= w) {
                maxVal += items[i].second;
                w -= items[i].first;
            } else {
                maxVal += (w / (double) items[i].first) * (double) items[i].second;
            }
        }

        return maxVal;
    }
};

int main() {
    vector<pair<int, int>> items = {
            {50,  40},
            {40,  50},
            {90,  25},
            {120, 100},
            {10,  30},
            {200, 45},
    };

    Solution solution;

    cout << solution.maximumValue(items, 6, 200);


    return 0;
}