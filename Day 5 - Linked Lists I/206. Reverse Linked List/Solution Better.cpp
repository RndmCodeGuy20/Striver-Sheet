//
// Created by SHANTANU on 11-06-2023.
//
#include <bits/stdc++.h>
#include "../Linked List.h"

using namespace std;

class Solution {
public:
    Node *reverseList(Node *head) {
        Node *prev = NULL, *temp = NULL;
        Node *curr = head;

        while (curr) {
            temp = curr;
            curr = curr->next;
            temp->next = prev;
            prev = temp;
        }

        return prev;
    }
};

int main() {
    int nums[] = {1, 2, 3, 4};
    LinkedList linkedList(nums, 4);

    Solution solution;
    Node *ptr = solution.reverseList(linkedList.head);

    while (ptr) {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }

    return 0;
}