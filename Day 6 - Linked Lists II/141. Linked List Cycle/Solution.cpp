//
// Created by SHANTANU on 12-06-2023.
//
#include <bits/stdc++.h>
#include "../Linked List.h"

using namespace std;

class Solution {
public:
    bool hasCycle(Node *head) {
        if (!head) {
            return false;
        }

        Node *slow = head, *fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                return true;
            }
        }

        return false;
    }
};

int main() {

    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    LinkedList ll(arr, n);
//    ll.head->next->next->next->next->next = ll.head->next->next;

    Solution solution;

    cout << solution.hasCycle(ll.head);

    return 0;
}