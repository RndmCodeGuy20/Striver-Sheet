//
// Created by SHANTANU on 28-06-2023.
//
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> mergeKSortedArrays(vector<vector<int>> &arr) {
        vector<int> result;
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;

        for (int i = 0; i < arr.size(); ++i) {
            pq.push({arr[i][0], {i, 0}});
        }

        while (!pq.empty()) {
            pair<int, pair<int, int>> temp = pq.top();
            pq.pop();

            result.push_back(temp.first);

            if (temp.second.second + 1 < arr[temp.second.first].size()) {
                pq.push({arr[temp.second.first][temp.second.second + 1], {temp.second.first, temp.second.second + 1}});
            }
        }

        return result;
    }
};

int main() {
    Solution solution;
    vector<vector<int>> arr = {{2, 6, 12, 15},
                               {1, 3, 14, 20},
                               {3, 5, 8,  10}};

    vector<int> result = solution.mergeKSortedArrays(arr);

    for (int i = 0; i < result.size(); ++i) {
        cout << result[i] << " ";
    }


    return 0;
}