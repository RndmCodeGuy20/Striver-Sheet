//
// Created by SHANTANU on 08-07-2023.
//
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void stringCombination(string temp, int index, int size, string charList) {
        if (index == size && temp == "shant") {
            cout << temp << endl;
            return;
        }

        for (int i = 0; i < charList.length(); ++i) {
            temp.push_back(charList[i]);
            stringCombination(temp, index + 1, size, charList);
            temp.pop_back();
        }
    }
};

int main() {

    Solution solution;
    solution.stringCombination("", 0, 5, "ahntsu");

    return 0;
}