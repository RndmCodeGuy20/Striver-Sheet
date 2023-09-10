//
// Created by SHANTANU on 10-07-2023.
//
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int rez = 0;
        set<char> charSet;
        int left = 0;

        for (int right = 0; right < s.size(); ++right) {
            while (charSet.find(s[right]) != charSet.end()) {
                charSet.erase(s[left]);
                left++;
            }
            charSet.insert(s[right]);
            rez = max(rez, right - left + 1);
        }

        return rez;
    }
};

int main() {


    return 0;
}