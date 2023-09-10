//
// Created by SHANTANU on 08-07-2023.
//
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void binaryCombinations(vector<int> temp, vector<vector<int>> &rez, int index, int size) {
        if (index == size) {
            rez.push_back(temp);
            return;
        }

        temp.push_back(1);
        binaryCombinations(temp, rez, index + 1, size);
        temp.pop_back();

        temp.push_back(0);
        binaryCombinations(temp, rez, index + 1, size);
        temp.pop_back();
    }
};

int main() {
    Solution solution;
    vector<vector<int>> rez;
    vector<int> temp;

    solution.binaryCombinations(temp, rez, 0, 2);

    for (auto &row: rez) {
        for (auto item: row) {
            cout << item << " ";
        }
        cout << endl;
    }

    return 0;
}