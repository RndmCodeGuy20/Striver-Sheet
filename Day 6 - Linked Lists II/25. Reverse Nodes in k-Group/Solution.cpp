//
// Created by SHANTANU on 12-06-2023.
//
#include <bits/stdc++.h>
#include "../Linked List.h"

using namespace std;

class Solution {
public:
    Node *reverseKGroup(Node *head, int k) {
        if (!head || k == 1) {
            return head;
        }

        Node *dummy = new Node(0);
        dummy->next = head;

        Node *curr = dummy, *nex = dummy, *pre = dummy;
        int count = 0;

        while (curr->next) {
            curr = curr->next;
            count++;
        }

        while (count >= k) {
            curr = pre->next;
            nex = curr->next;

            for (int i = 1; i < k; i++) {
                curr->next = nex->next;
                nex->next = pre->next;
                pre->next = nex;
                nex = curr->next;
            }

            pre = curr;
            count -= k;
        }

        return dummy->next;
    }
};

int main() {

    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    LinkedList ll(arr, n);

    Solution solution;

    Node *ptr = solution.reverseKGroup(ll.head, 2);

    while (ptr) {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }

    return 0;
}