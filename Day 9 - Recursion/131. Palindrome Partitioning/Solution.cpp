//
// Created by SHANTANU on 24-06-2023.
//
#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    bool isPalindrome(string s) {
        int i = 0, j = s.length() - 1;
        while (i < j) {
            if (s[i] != s[j]) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }

    void generatePartitions(const string &s, vector<vector<string>> &result, vector<string> &current, int start) {
        if (start >= s.length()) {
            result.push_back(current);
            return;
        }
        for (int i = start; i < s.length(); i++) {
            string sub = s.substr(start, i - start + 1);
            if (isPalindrome(sub)) {
                current.push_back(sub);
                generatePartitions(s, result, current, i + 1);
                current.pop_back();
            }
        }
    }

public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> current;
        generatePartitions(s, result, current, 0);
        return result;
    }
};

int main() {
    Solution solution;
    vector<vector<string>> result = solution.partition("aabb");

    for (auto &i: result) {
        cout << "[";
        for (const auto &j: i) {
            cout << j << ", ";
        }
        cout << "]" << endl;
    }

    return 0;
}