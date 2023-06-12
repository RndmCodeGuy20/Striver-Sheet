//
// Created by SHANTANU on 11-06-2023.
//
#include <bits/stdc++.h>
#include "../Linked List.h"

using namespace std;

class Solution {
public:
    Node *removeNthFromEnd(Node *head, int n) {
        Node *ptr = head, *prev = NULL;
        int length = 0;

        while (ptr) {
            length++;
            ptr = ptr->next;
        }

        ptr = head;
        int i = 0;
        while (i < (length - n)) {
            prev = ptr;
            ptr = ptr->next;
            i++;
        }

        prev->next = ptr->next;

        return head;
    }
};

using namespace std;

int main() {

    int nums[] = {1, 2, 3, 4, 5};
    LinkedList linkedList(nums, 5);

    Solution solution;
    Node *ptr = solution.removeNthFromEnd(linkedList.head, 2);

    while (ptr) {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }

    return 0;
}