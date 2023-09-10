/**
 * Created by SHANTANU on 20-08-2023.
 * Topic - 
*/
#include <bits/stdc++.h>

using namespace std;

class Solution {
private:

public:
    string obfuscateMailId(string emailID) {
        int ind = 0;
        string res;
        for (int i = 0; i < emailID.length(); ++i) {
            if (emailID[i] == '@') {
                ind = i;
                break;
            }
        }

        if (ind == 0) {
            return "error";
        } else if (ind < 6) {
            for (int i = 0; i < ind; ++i) {
                emailID[i] = '*';
            }
        } else {
            for (int i = 3; i < ind; ++i) {
                emailID[i] = '*';
            }
        }

        return emailID;
    }
};

int main() {
    Solution solution;
    string s;
    cin >> s;

    cout << solution.obfuscateMailId(s);

    return 0;
}