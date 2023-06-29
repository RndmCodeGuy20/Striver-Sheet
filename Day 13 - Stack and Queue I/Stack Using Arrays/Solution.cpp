//
// Created by SHANTANU on 29-06-2023.
//
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

//    Stack(int data[], int size) {
//        this->size = size;
//        front = new int[this->size];
//
//        for (int i = 0; i < size; ++i) {
//            front[i] = data[i];
//            top++;
//        }
//    }

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

    void printStackInfo() {
        printf("stack size : %d\nstack capacity : %d\nstack top : %d\n", this->size, this->maxSize, this->top);
//        printf("stack data : ");
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

int main() {
    Stack stack(10);

    stack.push(1);
    stack.push(1);

    cout << stack.empty() << endl;

    stack.printStackInfo();

    cout << endl << stack.pop() << endl;

    stack.printStackInfo();

    return 0;
}