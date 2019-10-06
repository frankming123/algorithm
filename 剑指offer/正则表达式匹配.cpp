#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    bool match(char *str, char *pattern) {
        // printf("str:%c pattern:%c\n", *str, *pattern);
        if (*str == '\0' && *pattern == '\0')
            return true;
        else if (*pattern == '\0')
            return false;
        if (*(pattern + 1) == '*') {
            if (*str == '\0')
                return match(str, pattern + 2);
            else if (*pattern == '.' || *str == *pattern)
                return match(str + 1, pattern) || match(str + 1, pattern + 2) || match(str, pattern + 2);
            else
                return match(str, pattern + 2);
        }
        if (*str == '\0')
            return false;
        if (*pattern == '.' || *str == *pattern)
            return match(str + 1, pattern + 1);
        else
            return false;
    }
};
int main() {
    Solution s;
    char *s1 = "a", *s2 = "a*a";
    cout << s.match(s1, s2);
    return 0;
}