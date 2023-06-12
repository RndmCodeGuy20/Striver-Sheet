//
// Created by SHANTANU on 11-06-2023.
//
#include <bits/stdc++.h>
#include "../Linked List.h"

using namespace std;

class Solution {
public:
    Node *middleNode(Node *head) {
        Node *ptr = head;
        int length = 0;

        while (ptr) {
            length++;
            ptr = ptr->next;
        }

        ptr = head;

        for (int i = 0; i < length / 2; ++i) {
            ptr = ptr->next;
        }

        return ptr;
    }
};

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6};
    LinkedList linkedList(arr, 6);

    Solution solution;
    cout << solution.middleNode(linkedList.head)->data;


    return 0;
}