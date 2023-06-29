//
// Created by SHANTANU on 29-06-2023.
//

#ifndef STRIVER_SHEET_STACK_H
#define STRIVER_SHEET_STACK_H

#include <bits/stdc++.h>

using namespace std;

class Stack {
public:
    int top = -1;
    int *front;
    int size = 0;
    int maxSize;

    Stack(int maxSize) {
        this->maxSize = maxSize;
        this->front = new int[this->maxSize];
    }

    bool empty() {
        return this->top == -1;
    }

    void push(int el) {
        if (this->top == this->maxSize - 1) {
            cout << "overflow" << endl;
            return;
        } else {
            this->front[++this->top] = el;
            ++size;
        }
    }

    int pop() {
        if (this->top == -1) {
            cout << "underflow";
            return -1;
        }
        int el = this->front[this->top];
        this->top--;
        this->size--;

        return el;
    }

    int peek() {
        return this->top;
    }

    void printStackInfo() {
        printf("stack size : %d\nstack capacity : %d\nstack top : %d\n", this->size, this->maxSize, this->top);
        for (int i = 0; i <= this->top; ++i) {
            cout << "+---";
        }
        cout << "+" << endl << "| ";
        for (int i = 0; i <= this->top; ++i) {
            cout << front[i] << " | ";
        }
        cout << endl;
        for (int i = 0; i <= this->top; ++i) {
            cout << "+---";
        }
        cout << "+";
    }
};

#endif //STRIVER_SHEET_STACK_H
