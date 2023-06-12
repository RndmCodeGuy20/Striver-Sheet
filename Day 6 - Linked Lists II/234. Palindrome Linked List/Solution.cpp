//
// Created by SHANTANU on 12-06-2023.
//
#include <bits/stdc++.h>
#include "../Linked List.h"

using namespace std;

class Solution {
public:
    bool isPalindrome(Node *head) {
        // find middle of the linked list
        Node *slow = head, *fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // check linked list from middle and start one element at a time
        Node *prev = nullptr, *curr = slow, *next = nullptr;

        while (curr != nullptr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        Node *ptr = head;

        while (prev != nullptr) {
            if (prev->data != ptr->data) {
                return false;
            }
            prev = prev->next;
            ptr = ptr->next;
        }

        return true;
    }
};

int main() {
    int array[] = {1, 2, 2, 2};
    LinkedList *list = new LinkedList(array, 4);

    Solution solution;

    cout << solution.isPalindrome(list->head) << endl;

    return 0;
}