//
// Created by SHANTANU on 07-07-2023.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    static bool comp(pair<int, int> a, pair<int, int> b) {
        return a.second < b.second;
    }

public:
    vector<int> topKFrequent(vector<int> &nums, int k) {
        map<int, int> count;
        for (const auto &item: nums) {
            count[item]++;
        }

//        sort(count.begin(), count.end(), comp);
//        don't know how to sort, deprecate - try heaps
    }
};

int main() {


    return 0;
}