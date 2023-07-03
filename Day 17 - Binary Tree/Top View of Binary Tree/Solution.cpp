//
// Created by SHANTANU on 03-07-2023.
//
#include <bits/stdc++.h>
#include "../Binary Tree.h"

using namespace std;

class Solution {
public:
    vector<int> topView(Node *root) {
        queue<pair<Node *, int>> Q;
        unordered_map<int, int> ordMap;

        Q.emplace(root, 0);
        pair<Node *, int> temp;

        while (!Q.empty()) {
            temp = Q.front();
            Q.pop();

//            ordMap[temp.second] = temp.first->data;
            if (ordMap.find(temp.second) == ordMap.end()) ordMap[temp.second] = temp.first->data;

            if (temp.first->left) {
                Q.emplace(temp.first->left, temp.second - 1);
            }
            if (temp.first->right) {
                Q.emplace(temp.first->right, temp.second + 1);
            }
        }

        vector<int> rez;
        for (auto &item: ordMap) {
            cout << item.first << " " << item.second << endl;
            rez.push_back(item.second);
        }

        return rez;
    }
};

int main() {
    Solution solution;
    Tree tree({1, 2, 3, 4, 5, 6, 7});

    vector<int> rez = solution.topView(tree.root);
//    for (int item: rez) {
//        cout << item << " ";
//    }


    return 0;
}