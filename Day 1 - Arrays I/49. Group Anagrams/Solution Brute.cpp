//
// Created by SHANTANU on 07-07-2023.
//
#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    static bool matchStrings(string s1, string s2) {
        if (s1.length() != s2.length()) return false;
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());

        for (int i = 0; i < s1.length(); ++i) {
            if (s1[i] != s2[i]) return false;
        }

        return true;
    }

public:
    vector<vector<string>> groupAnagrams(vector<string> &strs) {
        vector<bool> visited(strs.size(), false);
        vector<vector<string>> rez;

        for (int i = 0; i < strs.size(); ++i) {
            if (!visited[i]) {
                vector<string> temp;
                temp.push_back(strs[i]);
                for (int j = i + 1; j < strs.size(); ++j) {
                    if (matchStrings(strs[i], strs[j])) {
                        temp.push_back(strs[j]);
                        visited[j] = true;
                    }
                }
                rez.push_back(temp);
            }
        }

        return rez;
    }
};

int main() {
    Solution solution;
//    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<string> strs = {"a"};
    vector<vector<string>> rez = solution.groupAnagrams(strs);

    sort(rez.begin(), rez.end());

    for (const auto &item: rez) {
        for (const auto &item1: item) {
            cout << item1 << " ";
        }
        cout << endl;
    }

    return 0;
}