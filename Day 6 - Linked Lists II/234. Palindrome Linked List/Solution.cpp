//
// Created by SHANTANU on 12-06-2023.
//
#include <bits/stdc++.h>
#include "../Linked List.h"

using namespace std;

class Solution {
public:
    bool isPalindrome(Node *head) {
        Node *slow = head, *fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        Node *curr = slow, *next = nullptr, *prev = nullptr;

        while (curr && curr->next) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        if (curr) {
            curr->next = prev;
        }

        Node *ptr = head;
        while (ptr) {
            cout << ptr->data << " ";
            ptr = ptr->next;
        }

        return true;
    }
};

int main() {
    int array[] = {1, 2, 2, 1};
    LinkedList list(array, 4);

    Solution solution;

    solution.isPalindrome(list.head);

    return 0;
}