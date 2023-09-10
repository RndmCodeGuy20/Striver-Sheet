//
// Created by SHANTANU on 07-07-2023.
//
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int> &nums, int k) {
        map<int, int> count;
        map<int, vector<int>> bucket;
        vector<int> rez;

        for (auto el: nums) {
            count[el]++;
        }

        for (auto item: count) {
            bucket[item.second].push_back(item.first);
        }

        auto it = bucket.rbegin();

        while (it != bucket.rend()) {
            if (k <= 0) break;
            cout << it->first << " ";
            for (const auto &item: it->second) {
                if (k <= 0) break;
                rez.push_back(item);
                cout << item << " ";
                k--;
            }
            cout << endl;

            it++;
        }

        return rez;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 1, 1, 2, 2, 2, 3};
    vector<int> rez = solution.topKFrequent(nums, 2);

    cout << endl;
    for (auto item: rez) {
        cout << item << " ";
    }

    return 0;
}