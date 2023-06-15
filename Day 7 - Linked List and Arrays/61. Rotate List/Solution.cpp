//
// Created by SHANTANU on 15-06-2023.
//
#include <bits/stdc++.h>
#include "../../Day 6 - Linked Lists II/Linked List.h"

using namespace std;


class Solution {
public:
    Node *rotateRight(Node *head, int k) {
        Node *ptr = head;
        int length = 0;
        while (ptr) {
            length++;
            ptr = ptr->next;
        }
        k = k % length;

        while (k) {
            ptr = head;
            while (ptr->next->next) {
                ptr = ptr->next;
            }
            ptr->next->next = head;
            head = ptr->next;
            ptr->next = nullptr;
            k--;
        }

        return head;
    }
};

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    LinkedList *linkedList = new LinkedList(arr, 5);

    Solution solution;

//    Node *ptr = solution.rotateRight(linkedList->head, 2);
    Node *ptr = solution.rotateRight(linkedList->head, 5); // same as k = 2

    while (ptr) {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    return 0;
}