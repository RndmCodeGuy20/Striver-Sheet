//
// Created by SHANTANU on 15-06-2023.
//
#include <bits/stdc++.h>
#include "../Linked List.h"

using namespace std;


class Solution {
public:
    Node *copyRandomList(Node *head) {
        Node *ptrA = head->next;
        Node *headB = new Node(head->data);
        Node *ptrB = headB;
        map<Node *, Node *> map;
        map[head] = headB;

        while (ptrA) {
            Node *newNode = new Node(ptrA->data);
            ptrB->next = newNode;
            ptrB = ptrB->next;
            map[ptrA] = ptrB;
            ptrA = ptrA->next;
        }

        for (auto item: map) {
            printf("%x --> %x\n", item.first, item.second);
        }

        return headB;
    }
};

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    LinkedList *linkedList = new LinkedList(arr, 5);

    Solution solution;

    Node *ptr = solution.copyRandomList(linkedList->head);

//    while (ptr) {
//        cout << ptr->data << " ";
//        ptr = ptr->next;
//    }


    return 0;
}