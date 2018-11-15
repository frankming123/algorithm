/*
1005 Spell It Right （20 分）
Given a non-negative integer N, your task is to compute the sum of all the digits of N, and output every digit of the sum in English.

Input Specification:
Each input file contains one test case. Each case occupies one line which contains an N (≤10
​100
​​ ).

Output Specification:
For each test case, output in one line the digits of the sum in English words. There must be one space between two consecutive words, but no extra space at the end of a line.

Sample Input:
12345
Sample Output:
one five
*/
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main(int argc, char const *argv[]) {
    string s;
    cin >> s;
    int res = 0;
    for (int i = 0; i < s.length(); i++)
        res += s[i] - '0';

    stringstream sstream;
    sstream << res;
    s = sstream.str();
    bool flag = false;
    for (int i = 0; i < s.length(); i++) {
        switch (s[i]) {
        case '0':
            printf("%szero", flag ? " " : "");
            break;
        case '1':
            printf("%sone", flag ? " " : "");
            break;
        case '2':
            printf("%stwo", flag ? " " : "");
            break;
        case '3':
            printf("%sthree", flag ? " " : "");
            break;
        case '4':
            printf("%sfour", flag ? " " : "");
            break;
        case '5':
            printf("%sfive", flag ? " " : "");
            break;
        case '6':
            printf("%ssix", flag ? " " : "");
            break;
        case '7':
            printf("%sseven", flag ? " " : "");
            break;
        case '8':
            printf("%seight", flag ? " " : "");
            break;
        case '9':
            printf("%snine", flag ? " " : "");
            break;
        }
        flag = true;
    }
    return 0;
}
