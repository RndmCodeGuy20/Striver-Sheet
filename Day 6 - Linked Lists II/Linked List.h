//
// Created by SHANTANU on 11-06-2023.
//

#ifndef STRIVER_SHEET_LINKED_LIST_H
#define STRIVER_SHEET_LINKED_LIST_H

class Node {
public:
    int data;
    Node *next;

    Node(int data, Node *next) {
        this->data = data;
        this->next = next;
    }
    Node(int data){
        this->data = data;
        this->next = nullptr;
    }
};

class LinkedList {
public:
    Node *head;
    int length;

    LinkedList(int array[], int length) {
        head = new Node(array[0], nullptr);
        Node *ptr = head;
        this->length = length;

        for (int i = 1; i < length; ++i) {
            Node *newNode = new Node(array[i], nullptr);
            ptr->next = newNode;
            ptr = ptr->next;
        }
    }
};

#endif //STRIVER_SHEET_LINKED_LIST_H
