/*
1048 数字加密 （20 分）
本题要求实现一种数字加密方法。首先固定一个加密用正整数 A，对任一正整数 B，将其每 1 位数字与 A 的对应位置上的数字进行以下运算：对奇数位，对应位的数字相加后对 13 取余——这里用 J 代表 10、Q 代表 11、K 代表 12；对偶数位，用 B 的数字减去 A 的数字，若结果为负数，则再加 10。这里令个位为第 1 位。

输入格式：
输入在一行中依次给出 A 和 B，均为不超过 100 位的正整数，其间以空格分隔。

输出格式：
在一行中输出加密后的结果。

输入样例：
1234567 368782971
输出样例：
3695Q8118
*/
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[]) {
    string s1, s2;
    cin >> s1 >> s2;
    int slen1 = s1.length();
    int slen2 = s2.length();
    //if B is shorter than A, we need to insert zero
    if (slen2 < slen1) {
        s2.insert(0, slen1 - slen2, '0');
        slen2 = s2.length();
    }
    int slen = min(slen1, slen2);

    for (int i = 0; i < slen; i++) {
        char c1 = s1[slen1 - 1 - i];
        char c2 = s2[slen2 - 1 - i];
        if (i % 2 == 0) {
            c2 = (c1 - '0' + c2 - '0') % 13 + '0';
            if (c2 == '9' + 1)
                c2 = 'J';
            if (c2 == '9' + 2)
                c2 = 'Q';
            if (c2 == '9' + 3)
                c2 = 'K';
        } else {
            c2 = (c2 - c1 < 0 ? c2 + 10 - (c1 - '0') : c2 - c1 + '0');
        }
        s2.replace(slen2 - 1 - i, 1, 1, c2);
    }
    cout << s2;
    return 0;
}
