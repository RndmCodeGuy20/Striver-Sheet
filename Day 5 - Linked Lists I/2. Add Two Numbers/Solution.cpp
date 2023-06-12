//
// Created by SHANTANU on 11-06-2023.
//
#include <bits/stdc++.h>
#include "../Linked List.h"

using namespace std;


class Solution {
public:
    Node *addTwoNumbers(Node *l1, Node *l2) {
        Node *ptr1 = l1, *ptr2 = l2;
        Node *head = NULL, *ptr = NULL;
        int carry = 0;

        while (ptr1 || ptr2) {
            int sum = carry;
            if (ptr1) {
                sum += ptr1->data;
                ptr1 = ptr1->next;
            }
            if (ptr2) {
                sum += ptr2->data;
                ptr2 = ptr2->next;
            }

            if (sum >= 10) {
                carry = sum / 10;
                sum %= 10;
            } else {
                carry = 0;
            }

            Node *temp = new Node(sum, NULL);
            if (!head) {
                head = temp;
                ptr = head;
            } else {
                ptr->next = temp;
                ptr = ptr->next;
            }
        }

        if (carry) {
            Node *temp = new Node(carry, NULL);
            ptr->next = temp;
        }

        return head;
    }
};


int main() {
    int nums1[] = {2, 4, 3};
    int nums2[] = {5, 6, 4};

    LinkedList linkedList1(nums1, 3);
    LinkedList linkedList2(nums2, 3);

    Solution solution;
    Node *ptr = solution.addTwoNumbers(linkedList1.head, linkedList2.head);

    while (ptr) {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }


    return 0;
}