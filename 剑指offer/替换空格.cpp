#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

class Solution {
  public:
    void replaceSpace(char *str, int length) {
        char *res = new char[length * 3+1];
        int len = 0;
        for (int i = 0; i < length; i++) {
            if (str[i] == ' ') {
                res[len++] = '%';
                res[len++] = '2';
                res[len++] = '0';
            } else {
                res[len++] = str[i];
            }
        }
        res[len] = '\0';
        strcpy(str, res);
    }
};

int main() {
    char str[400];
    gets(str);
    Solution s;
    s.replaceSpace(str, strlen(str));
    printf("%s", str);
    return 0;
}