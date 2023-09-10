//
// Created by SHANTANU on 07-07-2023.
//
#include <bits/stdc++.h>

using namespace std;

class Heap {
public:
    int *arr;
    int size;
    int last = 0;

    Heap(int size) {
        arr = new int[size];
        this->size = size;
    }

    void insert(int val) {
        this->last++;
        int index = last;
        arr[index] = val;

        while (index > 1) {
            int parent = index / 2;
            if (arr[index] > arr[parent]) {
                swap(arr[index], arr[parent]);
                index = parent;
            } else return;
        }
    }

    int deleteEl() {
        if (last == 0) {
            cout << "nothing to delete";
            return -1;
        }
        // swap first and last node
        arr[1] = arr[this->last];

        // remove last node
        this->last--;

        // propagate root node to tree
        int index = 1;
        while (index < this->last) {
            int leftInd = 2 * index;
            int rightInd = 2 * index + 1;

            if (leftInd < this->last && arr[index] < arr[leftInd]) {
                swap(arr[index], arr[leftInd]);
                index = leftInd;
            } else if (rightInd < this->last && arr[index] < arr[rightInd]) {
                swap(arr[index], arr[rightInd]);
                index = rightInd;
            } else return arr[this->last + 1];
        }

        return arr[this->last + 1];
    }


    void Heapify(int &nums) {
        
    }
};

int main() {
    Heap heap(10);

    heap.insert(50);
    heap.insert(40);
    heap.insert(30);
    heap.insert(60);

    heap.deleteEl();

    for (int i = 1; i < heap.last + 1; ++i) {
        cout << heap.arr[i] << " ";
    }

    return 0;
}