//
// Created by SHANTANU on 03-06-2023.
//
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        double res = 1.000000;
        if (x == 1) {
            return x;
        }
        if (n < 0) {
            for (int i = 0; i < abs(n); i++) {
                res = res / x;
            }
            return res;
        }
        for (int i = 0; i < n; i++) {
            res *= x;
        }

        return res;
    }
};

int main() {

    Solution solution;
    cout << solution.myPow(0.25, -23984932);


    return 0;
}