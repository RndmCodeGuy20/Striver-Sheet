/**
 * Created by SHANTANU on 11-08-2023.
 * Topic - Insertion in BST
*/
#include <bits/stdc++.h>
#include "./BST.h"

using namespace std;

class Solution {
public:
    Node *Insert(Node *ptr, Node *node) {
        if (!ptr) {
            return node;
        }

        if (node->data > ptr->data) {
            ptr->right = Insert(ptr->right, node);
        } else {
            ptr->left = Insert(ptr->left, node);
        }

        return ptr;
    }
};

int main() {
    BST bst(20);
    Solution solution;

    bst.root = solution.Insert(bst.root, new Node(10));
    bst.root = solution.Insert(bst.root, new Node(22));
    bst.root = solution.Insert(bst.root, new Node(12));
    bst.root = solution.Insert(bst.root, new Node(18));
    bst.PreOrder(bst.root);

    return 0;
}