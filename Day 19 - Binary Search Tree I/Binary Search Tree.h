//
// Created by SHANTANU on 04-07-2023.
//

#ifndef INTERVIEW_PREPARATION_BINARY_SEARCH_TREE_H
#define INTERVIEW_PREPARATION_BINARY_SEARCH_TREE_H

#include <bits/stdc++.h>

using namespace std;

template<typename nodeType>
class Node {
public:
    nodeType data;
    Node *left;
    Node *right;

    Node(nodeType data) {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

template<typename treeType>
class BinarySearchTree {
public:
    Node<treeType> *root = nullptr;

    BinarySearchTree(treeType data) {
        root = new Node<treeType>(data);
    }

    BinarySearchTree(vector<treeType> nums) {
        for (const auto &num: nums) {
            Insert(num);
        }
    }

    void Insert(treeType data) {
        Node<treeType> *ptr, *trail, *newNode;

        if (!root) {
            root = new Node<treeType>(data);
            return;
        }
        ptr = root;

        while (ptr) {
            trail = ptr;

            if (data <= ptr->data) ptr = ptr->left;
            else if (data > ptr->data) ptr = ptr->right;
            else return;
        }

        newNode = new Node<treeType>(data);

        if (data <= trail->data) trail->left = newNode;
        else if (data > trail->data) trail->right = newNode;
    }

    void PreOrder(Node<treeType> *q) {
        if (q == NULL) return;
        cout << q->data << " ";
        PreOrder(q->left);
        PreOrder(q->right);
    }
};

#endif //INTERVIEW_PREPARATION_BINARY_SEARCH_TREE_H
