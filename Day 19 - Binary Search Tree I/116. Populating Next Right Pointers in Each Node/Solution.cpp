//
// Created by SHANTANU on 04-07-2023.
//
#include <bits/stdc++.h>
#include "../Binary Search Tree.h"

using namespace std;

template<typename nodeType>
class Node2 : public Node<nodeType> {
public:
    Node2<nodeType> *next;

    Node2(nodeType data) : Node<nodeType>(data) {};
};

template<typename nodeType>
class Solution {
public:
    Node2<nodeType> *connect(Node2<nodeType> *root) {
        Node2<nodeType> *ptr;
        queue<Node2<nodeType>> Q;
        Q.push(root);
        Q.push(nullptr);

        while (!Q.empty()) {
            ptr = Q.front();
            Q.pop();

            if (!ptr) {
                if (!Q.empty()) {
                    Q.push(nullptr);
                    break;
                }
            } else {
                if (ptr->left) Q.push(ptr->left);
                if (ptr->right) Q.push(ptr->right);
            }
            ptr->next = Q.front();
        }
    }
};

int main() {


    return 0;
}