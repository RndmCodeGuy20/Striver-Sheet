//
// Created by SHANTANU on 01-07-2023.
//
#include <bits/stdc++.h>
#include "../Binary Tree.h"

using namespace std;

class Solution {
public:
    vector<int> postorderTraversal(Node *ptr) {
        stack<Node *> S;
        vector<int> rez;

        while (true) {
            while (ptr) {
                S.push(ptr);
                ptr = ptr->right;
            }
            if (S.empty()) break;
            ptr = S.top();
            S.pop();
            rez.push_back(ptr->data);
            ptr = ptr->left;
        }

        return rez;
    }
};

int main() {
    Tree tree({1, 2, 3, 4, 5, 6, 7});
    Solution solution;

    vector<int> rez = solution.postorderTraversal(tree.root);

    for (int i: rez) {
        cout << i << " ";
    }

    return 0;
}