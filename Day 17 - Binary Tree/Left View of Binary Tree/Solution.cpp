//
// Created by SHANTANU on 01-07-2023.
//
#include <bits/stdc++.h>
#include "../Binary Tree.h"

using namespace std;

class Solution {
private:
    void getLeftView(Node *ptr, int level, vector<int> &rez) {
        if (!ptr) return;

        if (level == rez.size()) rez.push_back(ptr->data);
        getLeftView(ptr->left, level + 1, rez);
        getLeftView(ptr->right, level + 1, rez);
    }

public:
    vector<int> leftView(Node *ptr) {
        vector<int> rez;
//        rez.push_back(ptr->data);
//        while (true) {
//            if (ptr->left) {
//                ptr = ptr->left;
//                rez.push_back(ptr->data);
//            } else if (ptr->right) {
//                ptr = ptr->right;
//                rez.push_back(ptr->data);
//            } else return rez;
//        }

        this->getLeftView(ptr, 0, rez);
        return rez;
    }
};

int main() {
    Tree tree({1, 2, 3, -1, -1, 4, 6, -1, 5, -1, -1, 7, -1});
    Solution solution;

    vector<int> rez = solution.leftView(tree.root);

    for (int i: rez) {
        cout << i << " ";
    }

    return 0;
}