#include <cstring>
#include <iostream>

using namespace std;

int main() {
    char str1[10240], str2[10240], res[10240];
    cin.getline(str1, 10240);
    cin.getline(str2, 10240);
    bool appeared[128] = {false};
    int len1 = strlen(str1), len2 = strlen(str2);
    for (int i = 0; i < len2; i++)
        appeared[str2[i]] = true;

    int len3 = 0;
    for (int i = 0; i < len1; i++) {
        if (!appeared[str1[i]]) {
            res[len3] = str1[i];
            len3++;
        }
    }
    res[len3] = '\0';
    printf("%s\n", res);
    return 0;
}