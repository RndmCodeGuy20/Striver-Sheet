/**
 * Created by SHANTANU on 19-08-2023.
 * Topic - The function accepts two positive integers ‘r’ and ‘unit’ and a positive integer array ‘arr’ of size ‘n’ as its argument ‘r’ represents the number of rats present in an area, ‘unit’ is the amount of food each rat consumes and each ith element of array ‘arr’ represents the amount of food present in ‘i+1’ house number, where 0 <= i
*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
private:

public:
    int ratHouseCount(int r, int unit, int n, const vector<int> &array) {
        if (array.empty()) return -1;
        int hunger = r * unit, temp = 0;

        for (int i = 0; i < array.size(); ++i) {
            temp += array[i];

            if (temp >= hunger) return i + 1;
        }

        return 0;
    }
};

int main() {
    Solution solution;
    int r;
    cin >> r;

    int unit;
    cin >> unit;

    int n;
    cin >> n;

    vector<int> array(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> array[i];
    }
    cout << solution.ratHouseCount(r, unit, n, array) << endl;

    return 0;
}