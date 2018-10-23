/*
1024 科学计数法 （20 分）
科学计数法是科学家用来表示很大或很小的数字的一种方便的方法，其满足正则表达式
[+-][1-9].[0-9]+E[+-][0-9]+，即数字的整数部分只有 1 位，小数部分至少有 1
位，该数字及其指数部分的正负号即使对正数也必定明确给出。

现以科学计数法的格式给出实数 A，请编写程序按普通数字表示法输出
A，并保证所有有效位都被保留。

输入格式：
每个输入包含 1 个测试用例，即一个以科学计数法表示的实数
A。该数字的存储长度不超过 9999 字节，且其指数的绝对值不超过 9999。

输出格式：
对每个测试用例，在一行中按普通数字表示法输出
A，并保证所有有效位都被保留，包括末尾的 0。

输入样例 1：
+1.23400E-03
输出样例 1：
0.00123400
输入样例 2：
-1.2E+10
输出样例 2：
-12000000000
*/
#include <iostream>
#include <string>

using namespace std;

void calc(string &s, int n) {
    if (n == 0)
        return;
    else if (n > 0) {
        size_t dotpos = s.find('.');
        if (dotpos != string::npos) {
            if (dotpos != s.length() - 2) {
                s.replace(dotpos, 1, 1, s[dotpos + 1]);
                s.replace(dotpos + 1, 1, 1, '.');
            } else {
                s.replace(dotpos, 1, 1, s[dotpos + 1]);
                s.pop_back();
            }
        } else {
            s.push_back('0');
        }
        if (s[0] == '0')
            s.erase(0, 1);
        calc(s, n - 1);
    } else {
        s.replace(1, 1, 1, s[0]);
        s[0] = '.';
        s.insert(0, 1, '0');
        calc(s, n + 1);
    }
}

int main(int argc, char const *argv[]) {
    string s;
    cin >> s;
    int pos = s.find('E');
    string first = s.substr(0, pos);
    int second = stoi(s.substr(pos + 1));

    bool isNeg = false;
    if (first[0] == '-')
        isNeg = true;
    first = first.substr(1);
    calc(first, second);
    if (isNeg)
        cout << "-";
    cout << first;
    return 0;
}
