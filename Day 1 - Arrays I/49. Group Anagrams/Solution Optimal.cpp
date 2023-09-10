//
// Created by SHANTANU on 07-07-2023.
//
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs) {
        map<string, vector<string>> msp;
        for (auto str: strs) {
            string temp = str;
            sort(str.begin(), str.end());
            msp[str].push_back(temp);
        }

        vector<vector<string>> rez;
        rez.reserve(msp.size());
        for (const auto &item: msp) {
            rez.push_back(item.second);
        }

        return rez;
    }
};

int main() {
    Solution solution;
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
//    vector<string> strs = {"a"};
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