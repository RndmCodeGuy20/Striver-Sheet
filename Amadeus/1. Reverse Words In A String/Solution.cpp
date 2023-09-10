/**
 * Created by SHANTANU on 16-08-2023.
 * Topic - Reverse all the words given in the string.
*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    void reverse(string &temp) {
        int i = 0, n = temp.size() - 1;

        while (i <= n) {
            swap(temp[i], temp[n]);
            i++;
            n--;
        }
    }

public:
    string reverseString(string &str) {
        string rez;
        string temp;

        for (int i = str.length() - 1; i >= 0; --i) {
            if (str[i] == ' ') {
//                if (temp == " ") break;
                reverse(temp);
                rez += temp;
//                if (temp.empty())
                rez += ' ';
                temp = "";
            } else
                temp += str[i];
        }
        reverse(temp);
        rez += temp;
        rez += ' ';

        return rez;
    }
};

int main() {
    Solution solution;
    string str = "a good example";

    cout << solution.reverseString(str);

    return 0;
}
