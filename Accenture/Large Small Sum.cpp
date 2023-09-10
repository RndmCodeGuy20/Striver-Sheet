/**
 * Created by SHANTANU on 20-08-2023.
 * Topic - 
*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    int findNumber(vector<int> arr, int index) {
        if (index == 0) {
            vector<int> evenArr;
            for (int i = 0; i < arr.size(); i += 2) {
                evenArr.push_back(arr[i]);
            }
            sort(evenArr.begin(), evenArr.end());
            return evenArr[evenArr.size() - 2];
        } else {
            vector<int> oddArr;
            for (int i = 1; i < arr.size(); i += 2) {
                oddArr.push_back(arr[i]);
            }
            sort(oddArr.begin(), oddArr.end());
            return oddArr[oddArr.size() - 2];
        }
    }

public:
    int largeSmallSum(const vector<int> &arr) {
        int smallest = findNumber(arr, 0), largest = findNumber(arr, 1);

        return smallest + largest;
    }
};

int main() {
    Solution solution;
    int n;
    cin >> n;
    vector<int> arr(n, -1);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cout << solution.largeSmallSum(arr);

    return 0;
}