//
// Created by SHANTANU on 11-06-2023.
//
#include <bits/stdc++.h>
#include "../Linked List.h"

using namespace std;

class Solution {
public:
    Node *reverseList(Node *head) {
        vector<int> nums;
        Node *ptr = head;

        while (ptr) {
            nums.push_back(ptr->data);
            ptr = ptr->next;
        }

        ptr = head;

        for (int i = nums.size() - 1; i >= 0; i--) {
            ptr->data = nums[i];
            ptr = ptr->next;
        }

        return head;
    }
};

int main() {
    int nums[] = {1, 2, 3, 4};
    LinkedList linkedList(nums, 4);
    Solution solution;

    Node *head = linkedList.head;

    Node *ptr = solution.reverseList(head);
    while (ptr) {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }

    return 0;
}