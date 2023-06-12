//
// Created by SHANTANU on 11-06-2023.
//
#include <bits/stdc++.h>
#include "../Linked List.h"

using namespace std;

class Solution {
public:
    void deleteNode(Node *node) {
//        Node *ptr = node, *q = node;
//
//        while (ptr->next) {
//            q = ptr;
//            ptr->data = ptr->next->data;
//            ptr = ptr->next;
//        }
//
//        q->next = NULL;
        *node = *node->next;
    }
};

int main() {
    int nums[] = {1, 2, 3, 4};
    LinkedList linkedList(nums, 4);

    Node *node = linkedList.head->next;

    Solution solution;
    solution.deleteNode(node);

    Node *ptr = linkedList.head;
    while (ptr) {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }

    return 0;
}