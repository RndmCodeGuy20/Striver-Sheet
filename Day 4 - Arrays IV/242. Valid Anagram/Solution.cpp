//
// Created by SHANTANU on 25-06-2023.
//
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
//        if (s.length() != t.length()) return false;
//
//        sort(s.begin(), s.end());
//        sort(t.begin(), t.end());
//
//        for (int i = 0; i < s.length(); ++i) {
//            if (s[i] != t[i]) return false;
//        }
//        return true;
        unordered_map<char, int> ms;
        unordered_map<char, int> mt;

        for (int i = 0; i < s.length(); ++i) {
            ms[s[i]]++;
            mt[t[i]]++;
        }

        if (ms.size() != mt.size()) return false;

        for (auto i: ms) {
            if (i.second != mt[i.first]) return false;
        }

        return true;
    }
};

int main() {
    Solution solution;

    cout << solution.isAnagram("anagram", "nagaram");

    return 0;
}