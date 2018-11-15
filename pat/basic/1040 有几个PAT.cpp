/*
1040 有几个PAT （25 分）
字符串 APPAPT 中包含了两个单词 PAT，其中第一个 PAT 是第 2 位(P)，第 4 位(A)，第 6 位(T)；第二个 PAT 是第 3 位(P)，第 4 位(A)，第 6 位(T)。

现给定字符串，问一共可以形成多少个 PAT？

输入格式：
输入只有一行，包含一个字符串，长度不超过10
​5
​​ ，只包含 P、A、T 三种字母。

输出格式：
在一行中输出给定字符串中包含多少个 PAT。由于结果可能比较大，只输出对 1000000007 取余数的结果。

输入样例：
APPAPT
输出样例：
2
*/
#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;
    long slen = s.length();
    // long p[100000] = {0};
    long *p = new long[slen]();
    long *a = new long[slen]();
    long *t = new long[slen]();
    // long a[100000] = {0};
    // long t[100000] = {0};
    if (s[0] == 'P')
        p[0] = 1;
    for (long i = 1; i < slen; i++) {
        if (s[i] == 'P')
            p[i] = p[i - 1] + 1;
        else
            p[i] = p[i - 1];
    }
    for (long i = 1; i < slen; i++) {
        if (s[i] == 'A') {
            a[i] += p[i] + a[i - 1];
        } else
            a[i] = a[i - 1];
    }
    for (long i = 1; i < slen; i++) {
        if (s[i] == 'T') {
            t[i] += a[i] + t[i - 1];
        } else
            t[i] = t[i - 1];
    }
    printf("%ld", t[slen - 1] % 1000000007);
    delete p, a, t;
    return 0;
}
