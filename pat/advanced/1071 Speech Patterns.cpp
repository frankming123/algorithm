#include <cctype>
#include <cstring>
#include <iostream>
#include <map>

using namespace std;

struct ptrCmp {
    bool operator()(const char *s1, const char *s2) const {
        return strcmp(s1, s2) < 0;
    }
};

char *subStr(char *str, int pos, int len) {
    char *ch = (char *)malloc(len + 1);
    for (int i = 0; i < len; i++)
        ch[i] = str[pos + i];
    ch[len] = '\0';
    return ch;
}

int main() {
    char str[1048577];
    cin.getline(str, 1048576);
    int len = strlen(str);
    for (int i = 0; i < len; i++)
        if (isupper(str[i]))
            str[i] -= 'A' - 'a';
    map<char *, int, ptrCmp> mmap;
    int l = 0, r = 0;
    while (l < len) {
        while (l < len && !isalnum(str[l]))
            l++;
        if (l == len)
            break;
        r = l;
        while (r < len && isalnum(str[r]))
            r++;

        char *sstr = subStr(str, l, r - l);
        if (mmap.find(sstr) != mmap.end())
            mmap[sstr]++;
        else
            mmap[sstr] = 1;
        l = r;
    }
    char *res;
    int cnt = 0;
    for (auto it : mmap) {
        if (it.second > cnt) {
            res = it.first;
            cnt = it.second;
        } else if (it.second == cnt && strcmp(res, it.first) < 0)
            res = it.first;
    }
    printf("%s %d\n", res, cnt);
    return 0;
}