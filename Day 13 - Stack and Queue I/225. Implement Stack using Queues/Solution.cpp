//
// Created by SHANTANU on 29-06-2023.
//
#include <bits/stdc++.h>
#include "../Queue.h"

using namespace std;

class Solution {
public:
    Queue *q1;
    Queue *q2;

    Solution() {
        q1 = new Queue(10);
        q2 = new Queue(10);
    }

    void push(int x) {
        q1->enQueue(x);
    }

    int pop() {
        int temp, i = 0, n = q1->size;

        while (i < n - 1) {
            q2->enQueue(q1->deQueue());
            i++;
        }
        temp = q1->deQueue();
        i = 0;
        n = q2->size;
        while (i < n) {
            q1->enQueue(q2->deQueue());
            i++;
        }

        return temp;
    }
};

int main() {
    Solution solution;
    solution.push(2);
    solution.push(3);
    solution.push(4);

    solution.q1->printQueueInfo();
    cout << endl;
    solution.q2->printQueueInfo();


    cout << solution.pop() << endl;

    solution.q1->printQueueInfo();
    cout << endl;
    solution.q2->printQueueInfo();

    return 0;
}