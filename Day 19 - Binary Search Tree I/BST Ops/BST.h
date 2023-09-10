/**
 * Created by SHANTANU on 11-08-2023.
 * Topic - 
*/

#ifndef STRIVER_SHEET_BST_H
#define STRIVER_SHEET_BST_H

#include <bits/stdc++.h>

using namespace std;

class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int data) {
        this->data = data;
        left = nullptr;
        right = nullptr;
    }
};

class BST {
public:
    Node *root = nullptr;

    BST(int root) {
        this->root = new Node(root);
    }

    void PreOrder(Node *ptr) {
        if (ptr == nullptr) return;
        cout << ptr->data << " ";
        PreOrder(ptr->left);
        PreOrder(ptr->right);
    }
};

#endif //STRIVER_SHEET_BST_H
