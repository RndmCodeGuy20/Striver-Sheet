//
// Created by SHANTANU on 01-07-2023.
//

#ifndef STRIVER_SHEET_BINARY_TREE_H
#define STRIVER_SHEET_BINARY_TREE_H

#include <bits/stdc++.h>

using namespace std;

class Node {
public:
    Node *left;
    int data;
    Node *right;

    Node(int data, Node *left, Node *right) {
        this->data = data;
        this->left = left;
        this->right = right;
    }
};

class Tree {
public:
    Node *root;

    Tree() {
        root = new Node(0, nullptr, nullptr);
    }

    Tree(vector<int> nums) {
        queue<Node *> Q;
        Node *temp, *newNode;
        int i = 0;

        root = new Node(nums[i], nullptr, nullptr);
        Q.push(root);

        while (!Q.empty() && i < nums.size() - 1) {
            i++;
            temp = Q.front();
            Q.pop();

            if (nums[i] != -1) {
                newNode = new Node(nums[i], nullptr, nullptr);
                temp->left = newNode;
                Q.push(newNode);
            }

            i++;
            if (nums[i] != -1) {
                newNode = new Node(nums[i], nullptr, nullptr);
                temp->right = newNode;
                Q.push(newNode);
            }
        }
    }
};

#endif //STRIVER_SHEET_BINARY_TREE_H
