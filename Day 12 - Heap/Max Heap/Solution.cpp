//
// Created by SHANTANU on 28-06-2023.
//
#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    void insertElement(vector<int> &arr, int n) {
        int i = n, temp = arr[n];

        while (i > 1 && temp > arr[i / 2]) {
            arr[i] = arr[i / 2];
            i /= 2;
        }
        arr[i] = temp;
    }

public:
    vector<int> heapifyArray(vector<int> arr) {
        for (int i = 2; i <= arr.size(); ++i) {
            this->insertElement(arr, i);
        }

        return arr;
    }
};

int main() {
    Solution solution;
    vector<int> arr = {0, 10, 20, 30, 25, 5, 40, 35};

    arr = solution.heapifyArray(arr);

    for (int i = 1; i < arr.size(); ++i) {
        cout << arr[i] << " ";
    }

    return 0;
}