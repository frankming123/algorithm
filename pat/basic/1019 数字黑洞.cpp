/*
1019 数字黑洞 （20 分）
给定任一个各位数字不完全相同的 4 位正整数，如果我们先把 4
个数字按非递增排序，再按非递减排序，然后用第 1 个数字减第 2
个数字，将得到一个新的数字。一直重复这样做，我们很快会停在有“数字黑洞”之称的
6174，这个神奇的数字也叫 Kaprekar 常数。

例如，我们从6767开始，将得到

7766 - 6677 = 1089
9810 - 0189 = 9621
9621 - 1269 = 8352
8532 - 2358 = 6174
7641 - 1467 = 6174
... ...
现给定任意 4 位正整数，请编写程序演示到达黑洞的过程。

输入格式：
输入给出一个 (0,104) 区间内的正整数 N。

输出格式：
如果 N 的 4 位数字全相等，则在一行内输出 N - N =
0000；否则将计算的每一步在一行内输出，直到 6174
作为差出现，输出格式见样例。注意每个数字按 4 位数格式输出。

输入样例 1：
6767
输出样例 1：
7766 - 6677 = 1089
9810 - 0189 = 9621
9621 - 1269 = 8352
8532 - 2358 = 6174
输入样例 2：
2222
输出样例 2：
2222 - 2222 = 0000
*/
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

string maxS(string &s) {
    char *cstr = (char *)s.c_str();
    int slen = s.length();
    sort(cstr, cstr + slen, [](char a, char b) -> bool { return a > b; });
    return cstr;
}
string minS(string &s) {
    char *cstr = (char *)s.c_str();
    int slen = s.length();
    sort(cstr, cstr + slen, [](char a, char b) -> bool { return a < b; });
    return cstr;
}
string sub(string &s1, string &s2) {
    char cstr[5];
    cstr[4] = '\0';
    int tmp = 0;
    for (int i = 3; i >= 0; i--) {
        cstr[i] = (10 + s1[i] - s2[i] - tmp) % 10 + '0';
        tmp = (10 + s1[i] - s2[i] - tmp) / 10 == 1 ? 0 : 1;
    }
    return cstr;
}

string add0(string &s) {
    string res = s;
    while (res.length() != 4) {
        res = "0" + res;
    }
    return res;
}

int main(int argc, char const *argv[]) {
    string s;
    cin >> s;
    s = add0(s);
    if (s[0] == s[1] && s[0] == s[2] && s[0] == s[3]) {
        cout << s << " - " << s << " = 0000" << endl;
        return 0;
    }
    if (s == "6174") {
        cout << "7641 - 1467 = 6174" << endl;
        return 0;
    }
    string maxs, mins;
    while (s != "6174") {
        maxs = maxS(s);
        mins = minS(s);
        s = sub(maxs, mins);
        cout << maxs << " - " << mins << " = " << s << endl;
    }
    return 0;
}