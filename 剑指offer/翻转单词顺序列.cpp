#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    string ReverseSentence(string str) {
        string res;
        int r = str.size();
        bool flag = false;
        for (int i = str.size() - 1; i >= 0; i--) {
            // printf("i:%d\n", i);
            if (str[i] == ' ') {
                res += str.substr(i + 1, r - i);
                if (!flag)
                    res += ' ';
                flag = true;
                r = i;
            }
        }
        res += str.substr(0, r);
        return res;
    }
};
int main() {
    Solution s;
    cout << s.ReverseSentence("student. a am I");
    return 0;
}