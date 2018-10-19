/*
1006 换个格式输出整数 （15 分）
让我们用字母 B 来表示“百”、字母 S 表示“十”，用 12...n 来表示不为零的个位数字 n（<10），换个格式来输出任一个不超过 3 位的正整数。例如 234 应该被输出为 BBSSS1234，因为它有 2 个“百”、3 个“十”、以及个位的 4。

输入格式：
每个测试输入包含 1 个测试用例，给出正整数 n（<1000）。

输出格式：
每个测试用例的输出占一行，用规定的格式输出 n。

输入样例 1：
234
输出样例 1：
BBSSS1234
输入样例 2：
23
输出样例 2：
SS123
作者: CHEN, Yue
单位: 浙江大学
时间限制: 400 ms
内存限制: 64 MB
代码长度限制: 16 KB
*/

#include <iostream>
#include <string>
using namespace std;

void printhundred(int n)
{
    while ((n--) > 0)
        printf("B");
}

void printten(int n)
{
    while ((n--) > 0)
        printf("S");
}

void printdigit(int n)
{
    for (int i = 1; i <= n; i++)
        printf("%d", i);
}

int main()
{
    string s;
    cin >> s;
    int slen = s.length();
    if (slen == 1)
        printdigit(int(s[0] - '0'));
    if (slen == 2)
    {
        printten(int(s[0] - '0'));
        printdigit(int(s[1] - '0'));
    }
    if (slen == 3)
    {
        printhundred(int(s[0] - '0'));
        printten(int(s[1] - '0'));
        printdigit(int(s[2] - '0'));
    }
    return 0;
}