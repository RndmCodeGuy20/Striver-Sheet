//
// Created by SHANTANU on 08-07-2023.
//
#include <bits/stdc++.h>
#include "../Linked List.h"

using namespace std;

class Solution {
public:
    bool detectCycle(Node *head) {
        Node *slow = head, *fast = head->next;

        while (slow != fast && slow && fast) {
            slow = slow->next;
            fast = fast->next->next;
        }
        if (slow != fast || !slow || !fast)
            return false;

        cout << slow->data << " " << fast->data << endl;

        return true;
    }
};

int main() {
    int nums[] = {1, 2, 3, 4, 5};
    LinkedList linkedList(nums, 5);
    Solution solution;

    Node *ptr = linkedList.head;

    while (ptr->next) {
        ptr = ptr->next;
    }

    ptr->next = linkedList.head->next;

    cout << solution.detectCycle(linkedList.head);
    return 0;
}