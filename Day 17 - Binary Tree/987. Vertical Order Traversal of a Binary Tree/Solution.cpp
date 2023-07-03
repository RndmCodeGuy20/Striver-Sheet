//
// Created by SHANTANU on 03-07-2023.
//
#include <bits/stdc++.h>
#include "../Binary Tree.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> topView(Node *root) {
        queue<pair<Node *, pair<int, int>>> Q;
        map<int, map<int, multiset<int>>> ordMap;

        Q.push({root, {0, 0}});
//        pair<Node *, int> temp;

        while (!Q.empty()) {
            auto temp = Q.front();
            Q.pop();

            ordMap[temp.second.first][temp.second.second];

            if (temp.first->left) {
                Q.push({temp.first->left, {temp.second.first - 1, temp.second.second + 1}});
            }
            if (temp.first->right) {
                Q.push({temp.first->right, {temp.second.first + 1, temp.second.second + 1}});
            }
        }

        vector<vector<int>> rez;

        rez.reserve(ordMap.size());
        for (auto &item: ordMap) {
            vector<int> col;
            for (const auto &q: item.second) {
                col.insert(col.end(), q.second.begin(), q.second.end());
            }
            rez.push_back(col);
        }

        return rez;
    }
};

int main() {
    Solution solution;
    Tree tree({1, 2, 3, 4, 6, 5, 7});

    vector<vector<int>> rez = solution.topView(tree.root);


    for (const auto &item: rez) {
        for (const auto &item1: item) {
            cout << item1 << " ";
        }
        cout << endl;
    }

    return 0;
}