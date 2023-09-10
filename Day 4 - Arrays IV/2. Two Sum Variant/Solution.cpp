/**
 * Created by SHANTANU on 19-08-2023.
 * Topic - Given an array of integers find two numbers that add up to be an exponent of 3
*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    bool isExponent(int num) {
        while (num % 3 == 0) {
            num /= 3;
        }

        return num == 1;
    }

    void isExponent2(int num) {
        cout << (log10(num) / log10(3)) << endl;
//        return (log10(num) / log10(3)) > 0;
    }

public:
    int twoSumVariant(vector<int> arr) {
        int res = 0;

        for (int i = 0; i < arr.size(); ++i) {
            for (int j = i + 1; j < arr.size(); ++j) {
//                if (isExponent(arr[i] + arr[j]))
                isExponent2(arr[i] + arr[j]);
//                res++;
            }
        }
        return res;
    }
};

int main() {
    Solution solution;
//    cout << solution.twoSumVariant({1, 2, 8, 7});

    return 0;
}