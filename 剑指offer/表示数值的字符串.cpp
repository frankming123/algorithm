#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool isNumeric(char *string) {
        bool hasE = false;
        bool hasDot = false;
        bool afterE = false;
        if (*string == '+' || *string == '-')
            string++;
        while (*string != '\0') {
            // printf("now:%c\n", *string);
            if (*string == 'e' || *string == 'E') {
                if (hasE)
                    return false;
                hasE = true;
                if (*(string + 1) == '-' || *(string + 1) == '+')
                    string++;
            } else if (*string == '.') {
                if (hasDot)
                    return false;
                if (hasE)
                    return false;
                hasDot = true;
            } else if (*string >= '0' && *string <= '9') {
                if (hasE)
                    afterE = true;
            } else
                return false;
            string++;
        }
        if (hasE && !afterE)
            return false;
        return true;
    }
};
int main() {
    Solution s;
    char str[100];
    fgets(str, 100, stdin);
    str[strlen(str) - 1] = '\0';

    cout << s.isNumeric(str);
    return 0;
}