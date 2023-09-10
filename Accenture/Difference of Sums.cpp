/**
 * Created by SHANTANU on 19-08-2023.
 * Topic - The function def differenceofSum(n. m) accepts two integers n, m as arguments Find the sum of all numbers in range from 1 to m(both inclusive) that are not divisible by n. Return difference between sum of integers not divisible by n with sum of numbers divisible by n.
*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
private:

public:
    int differenceOfSum(int n, int m) {
        int sum = 0;

        for (int i = 1; i <= m; ++i) {
            if (i % n == 0) {
                sum -= i;
            } else {
                sum += i;
            }
        }

        return sum;
    }
};

int main() {
    Solution solution;
    int n, m;
    cin >> n >> m;

    cout << solution.differenceOfSum(n, m);
    return 0;
}