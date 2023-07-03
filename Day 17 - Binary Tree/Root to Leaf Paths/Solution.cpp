//
// Created by SHANTANU on 03-07-2023.
//
#include <bits/stdc++.h>
#include "../Binary Tree.h"

using namespace std;

class Solution {
private:
//    void PrintArray(vector<int> path, vector<vector<int>> &rez) {
////        for (int i = 0; i < path.size(); ++i) {
////            cout << path[i] << " ";
////        }
//        cout << endl;
//    }

public:
    void PrintPathsRecursively(Node *ptr, vector<int> path, int pathLen, vector<vector<int>> &rez) {
        if (!ptr) return;

        path.push_back(ptr->data);
        pathLen++;

        if (!ptr->left && !ptr->right) rez.push_back(path);
        else {
            PrintPathsRecursively(ptr->left, path, pathLen, rez);
            PrintPathsRecursively(ptr->right, path, pathLen, rez);
        }
    }
};

int main() {
    Solution solution;
    Tree tree({1, 2, 3, 4, 5, 6, 7});
    vector<vector<int>> rez;

    solution.PrintPathsRecursively(tree.root, {}, 0, rez);

    for (const auto &item: rez) {
        for (auto el: item) {
            cout << el << " ";
        }
        cout << endl;
    }

    return 0;
}