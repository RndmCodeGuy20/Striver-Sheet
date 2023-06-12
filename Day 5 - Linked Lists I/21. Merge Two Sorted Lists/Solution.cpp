//
// Created by SHANTANU on 11-06-2023.
//
#include <bits/stdc++.h>
#include "../Linked List.h"

using namespace std;

class Solution {
public:
    Node *mergeTwoLists(Node *list1, Node *list2) {
        if (list1 == NULL && list2 == NULL) {
            return list1;
        } else if (list1 == NULL && list2 != NULL) {
            return list2;
        } else if (list1 != NULL && list2 == NULL) {
            return list1;
        }

        Node *list3, *last;

        if (list1->data < list2->data) {
            list3 = last = list1;
            list1 = list1->next;
            last->next = NULL;
        } else {
            list3 = last = list2;
            list2 = list2->next;
            last->next = NULL;
        }

        while (list1 && list2) {
            if (list1->data < list2->data) {
                last->next = list1;
                list1 = list1->next;
                last = last->next;
                last->next = NULL;
            } else {
                last->next = list2;
                list2 = list2->next;
                last = last->next;
                last->next = NULL;
            }
        }

        if (list1 != NULL && list2 == NULL) {
            last->next = list1;
        } else {
            last->next = list2;
        }

        return list3;
    }
};

int main() {
    int nums1[] = {1, 3, 4, 5, 6, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
    LinkedList linkedList1(nums1, 18);

    int nums2[] = {1, 3, 4};
    LinkedList linkedList2(nums2, 3);

    Solution solution;
    Node *ptr = solution.mergeTwoLists(linkedList1.head, linkedList2.head);

    while (ptr) {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }


    return 0;
}