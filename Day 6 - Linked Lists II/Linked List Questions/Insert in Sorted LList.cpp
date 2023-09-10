//
// Created by SHANTANU on 08-07-2023.
//
#include <bits/stdc++.h>
#include "../Linked List.h"

using namespace std;

class Solution {
public:
    void InsertInLL(Node *head, int val) {
        Node *newNode = new Node(val, nullptr);
        Node *ptr = head;

        while (ptr->next && ptr->next->data < newNode->data) {
            ptr = ptr->next;
        }

        newNode->next = ptr->next;
        ptr->next = newNode;
    }
};


int main() {
    int nums[] = {1, 4, 6};
    LinkedList linkedList(nums, 3);
    Solution solution;

    solution.InsertInLL(linkedList.head, 2);
    solution.InsertInLL(linkedList.head, 3);
    solution.InsertInLL(linkedList.head, 5);

    Node *ptr = linkedList.head;

    while (ptr) {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }


    return 0;
}

