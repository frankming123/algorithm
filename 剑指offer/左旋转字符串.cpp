#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    string LeftRotateString(string str, int n) {
        int len = str.length();
        if (len == 0)
            return "";
        n %= len;
        return str.substr(n) + str.substr(0, n);
    }
};
int main() {
    Solution s;
    cout << s.LeftRotateString("abcdef", 3);
    return 0;
}