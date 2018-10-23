/*
1016 部分A+B （15 分）
正整数 A 的“D​A（为 1 位整数）部分”定义为由 A 中所有 D​A组成的新整数 PA。例如：给定 A=3862767，DA=6，则 A 的“6 部分”PA是 66，因为 A 中有 2 个 6.现给定 A、DA、B、DB，请编写程序计算 PA+PB。

输入格式：
输入在一行中依次给出 A、D​A、B、DB，中间以空格分隔，其中 0<A,B<10​10。

输出格式：
在一行中输出 P​A+PB的值。

输入样例 1：
3862767 6 13530293 3
输出样例 1：
399
输入样例 2：
3862767 1 13530293 8
输出样例 2：
0
*/
#include <cstring>
#include <iostream>
#include <string>

using namespace std;

int strCount(string &s, char c) {
    int count = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == c)
            count++;
    }
    return count;
}

string strRepeat(char c, int count) {
    string s;
    for (int i = 0; i < count; i++)
        s += c;
    return s;
}

int main(int argc, char const *argv[]) {
    string str;
    char c;
    int count;
    long num;
    cin >> str >> c;
    count = strCount(str, c);
    num = atol(strRepeat(c, count).c_str());
    cin >> str >> c;
    count = strCount(str, c);
    num += atol(strRepeat(c, count).c_str());
    cout << num << endl;
    return 0;
}
