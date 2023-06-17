//
// Created by SHANTANU on 16-06-2023.
//
#include <bits/stdc++.h>

using namespace std;

struct train {
    int arrival;
    int departure;
};

class Solution {
private:
    static bool comparator(struct train t1, struct train t2) {
        if (t1.departure < t2.departure) return true;
        else if (t1.departure > t2.departure) return false;
        return false;
    }

public:
    int minimumPlatforms(int arrival[], int departure[], int n) {
        struct train reserve[n];
        vector<int> depTimes;

        for (int i = 0; i < n; i++) {
            reserve[i].arrival = arrival[i], reserve[i].departure = departure[i];
        }
        sort(reserve, reserve + n, this->comparator);

        depTimes.push_back(reserve[0].departure);
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < depTimes.size(); ++j) {
                if (reserve[i].arrival > depTimes[j]) {
                    depTimes[j] = reserve[i].departure;
                    break;
                } else if (j == depTimes.size() - 1) {
                    depTimes.push_back(reserve[i].departure);
                    break;
                }
            }
        }

        return depTimes.size();
    }
};

int main() {
    int arrival[] = {900, 1100, 1235};
    int departure[] = {1000, 1200, 1240};

    Solution solution;
    cout << solution.minimumPlatforms(arrival, departure, 3) << endl;


    return 0;
}