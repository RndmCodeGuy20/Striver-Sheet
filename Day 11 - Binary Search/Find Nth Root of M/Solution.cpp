//
// Created by SHANTANU on 27-06-2023.
//
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int NthRoot(int n, int m) {
        // considering constraints as 1 -> 10^9

        int low = 1, high = m, mid;

        while (low < high) {
            mid = (low + high) / 2;
            int power = pow(mid, n);
            if (power == m) {
                return mid;
            } else if (power > m) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }

        return -1;
    }

    int NthRootOptimal(int n, int m) {
        double low = 1, high = m, mid;
        double eps = 1e-6;

        while ((high - low) > eps) {
            mid = (low + high) / 2;
            double power = pow(mid, n);
            if (int(power) == m) {
                return int(mid);
            } else if (power > m) {
                high = mid;
            } else {
                low = mid;
            }
        }

        return -1;
    }
};

int main() {
    Solution solution;

    cout << solution.NthRootOptimal(9, 1953125);

    return 0;
}