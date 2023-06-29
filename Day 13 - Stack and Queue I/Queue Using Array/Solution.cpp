//
// Created by SHANTANU on 29-06-2023.
//
#include <bits/stdc++.h>

using namespace std;

class Queue {
public:
    int front = -1, rear = -1, size = 0, maxSize;
    int *ptr;

    Queue(int maxSize) {
        this->maxSize = maxSize;
        this->ptr = new int[this->maxSize];
    }

    void enQueue(int el) {
        try {
            if (this->size == this->maxSize) {
                throw ("overflow");
            } else {
                this->rear = (this->rear + 1) % this->maxSize;
                this->ptr[this->rear] = el;
                if (this->front == -1) this->front = this->rear;
                this->size++;
            }
        }
        catch (string err) {
            cout << err << endl;
        }
    }

    int deQueue() {
        int temp = 999;
        try {
            if (this->size == 0) {
                throw ("underflow");
            }
            temp = this->ptr[this->front];
            if (this->front == this->rear) {
                this->front = this->rear = -1;
                this->size = 0;
            } else {
                this->front = (this->front + 1) % this->maxSize;
                this->size--;
            }
        } catch (string err) {
            cout << err << endl;
            return temp;
        }

        return temp;
    }

    bool empty() {
        return this->size == 0;
    }

    int peekFront() {
        try {
            if (this->empty()) {
                throw ("underflow");
            } else {
                return this->ptr[this->front];
            }
        }
        catch (string err) {
            cout << err << endl;
        }

        return 999;
    }

    int peekRear() {
        try {
            if (this->empty()) {
                throw ("underflow");
            } else {
                return this->ptr[this->rear];
            }
        }
        catch (string err) {
            cout << err << endl;
        }

        return 999;
    }

    void printQueueInfo() {
        printf("queue size : %d\nqueue capacity : %d\nqueue front : %d\nqueue rear : %d\n",
               this->size,
               this->maxSize,
               this->front,
               this->rear
        );
        if (this->front == this->rear && this->rear == -1) return;
        for (int i = this->front; i <= this->rear; ++i) {
            cout << "+---";
        }
        cout << "+" << endl << "| ";
        for (int i = this->front; i <= this->rear; ++i) {
            cout << this->ptr[i] << " | ";
        }
        cout << endl;
        for (int i = this->front; i <= this->rear; ++i) {
            cout << "+---";
        }
        cout << "+";
    }
};

int main() {
    Queue queue(10);

    queue.enQueue(1);
    queue.enQueue(1);
    queue.enQueue(1);
    queue.enQueue(1);

    queue.printQueueInfo();

    cout << queue.deQueue() << endl;
    cout << queue.deQueue() << endl;
    cout << queue.deQueue() << endl;
    cout << queue.deQueue() << endl;

    queue.printQueueInfo();

    return 0;
}