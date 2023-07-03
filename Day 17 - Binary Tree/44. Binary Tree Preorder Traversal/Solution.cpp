//
// Created by SHANTANU on 01-07-2023.
//
#include <bits/stdc++.h>
#include "../Binary Tree.h"

using namespace std;

class Solution {
public:
    vector<int> preorderTraversal(Node *ptr) {
        stack<Node *> S;
        vector<int> rez;

        while (true) {
            while (ptr) {
                rez.push_back(ptr->data);
                S.push(ptr);
                ptr = ptr->left;
            }
            if (S.empty()) break;
            ptr = S.top();
            S.pop();
            ptr = ptr->right;
        }

        return rez;
    }
};

int main() {
    Tree tree({1, 2, 3, 4, 5, 6, 7});
    Solution solution;

    vector<int> rez = solution.preorderTraversal(tree.root);

    for (int i: rez) {
        cout << i << " ";
    }

    return 0;
}