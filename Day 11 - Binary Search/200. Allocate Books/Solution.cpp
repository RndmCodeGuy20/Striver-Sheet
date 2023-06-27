//
// Created by SHANTANU on 27-06-2023.
//
#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    bool isPossible(vector<int> &books, int people, int mid) {
        int count = 1, sum = 0;
        for (int i = 0; i < books.size(); i++) {
            sum += books[i];
            if (sum > mid) {
                count++;
                sum = books[i];
            }
            if (count > people) return false;
        }
        return true;
    }

public:
    int allocateBooks(vector<int> books, int people) {
        int low = 0, high = 0, mid, ans = INT_MAX;

        for (int i = 0; i < books.size(); i++) {
            low = max(low, books[i]);
            high += books[i];
        }

        while (low <= high) {
            mid = (low + high) / 2;

            if (isPossible(books, people, mid)) {
                ans = min(ans, mid);
                high = mid - 1;
            } else low = mid + 1;
        }

        return ans;
    }
};

int main() {
    Solution solution;
    vector<int> books = {12, 34, 67, 90};
    int people = 2;

    cout << solution.allocateBooks(books, people) << endl;


    return 0;
}