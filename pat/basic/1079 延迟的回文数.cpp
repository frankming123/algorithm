/*
1079 延迟的回文数 （20 分）
给定一个 k+1 位的正整数 N，写成 a
​k
​​ ⋯a
​1
​​ a
​0
​​  的形式，其中对所有 i 有 0≤a
​i
​​ <10 且 a
​k
​​ >0。N 被称为一个回文数，当且仅当对所有 i 有 a
​i
​​ =a
​k−i
​​ 。零也被定义为一个回文数。

非回文数也可以通过一系列操作变出回文数。首先将该数字逆转，再将逆转数与该数相加，如果和还不是一个回文数，就重复这个逆转再相加的操作，直到一个回文数出现。如果一个非回文数可以变出回文数，就称这个数为延迟的回文数。（定义翻译自 https://en.wikipedia.org/wiki/Palindromic_number ）

给定任意一个正整数，本题要求你找到其变出的那个回文数。

输入格式：
输入在一行中给出一个不超过1000位的正整数。

输出格式：
对给定的整数，一行一行输出其变出回文数的过程。每行格式如下

A + B = C
其中 A 是原始的数字，B 是 A 的逆转数，C 是它们的和。A 从输入的整数开始。重复操作直到 C 在 10 步以内变成回文数，这时在一行中输出 C is a palindromic number.；或者如果 10 步都没能得到回文数，最后就在一行中输出 Not found in 10 iterations.。

输入样例 1：
97152
输出样例 1：
97152 + 25179 = 122331
122331 + 133221 = 255552
255552 is a palindromic number.
输入样例 2：
196
输出样例 2：
196 + 691 = 887
887 + 788 = 1675
1675 + 5761 = 7436
7436 + 6347 = 13783
13783 + 38731 = 52514
52514 + 41525 = 94039
94039 + 93049 = 187088
187088 + 880781 = 1067869
1067869 + 9687601 = 10755470
10755470 + 07455701 = 18211171
Not found in 10 iterations.
*/
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

string add(string &s1, string &s2) {
    string s;
    int tmp = 0;
    int s1len = s1.length(), s2len = s2.length();
    int slen = max(s1len, s2len);
    for (int i = 0; i < slen; i++) {
        int n1 = i < s1len ? s1[s1len - 1 - i] - '0' : 0;
        int n2 = i < s2len ? s2[s2len - 1 - i] - '0' : 0;
        s += (n1 + n2 + tmp) % 10 + '0';
        tmp = (n1 + n2 + tmp) / 10;
    }
    if (tmp == 1)
        s += '1';
    reverse(s.begin(), s.end());
    int i = 0;
    while (s[i] == '0')
        i++;
    return s.substr(i);
}

bool isPali(string &s) {
    int slen = s.length();
    for (int i = 0; i < slen / 2; i++)
        if (s[i] != s[slen - 1 - i])
            return false;
    return true;
}

string sreverse(string &s) {
    int slen = s.length();
    char res[slen + 1];
    res[slen] = '\0';
    for (int i = 0; i < slen; i++)
        res[i] = s[slen - i - 1];
    return string(res);
}

int main(int argc, char const *argv[]) {
    string s;
    cin >> s;
    int n = 0;
    while (n++ < 10 && !isPali(s)) {
        string s1 = sreverse(s);
        string s2 = add(s, s1);
        cout << s << " + " << s1 << " = " << s2 << endl;
        s = s2;
    }
    if (isPali(s))
        cout << s << " is a palindromic number.";
    else
        cout << "Not found in 10 iterations.";
    return 0;
}
