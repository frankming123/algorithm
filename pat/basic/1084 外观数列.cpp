/*
1084 外观数列 （20 分）
外观数列是指具有以下特点的整数序列：

d, d1, d111, d113, d11231, d112213111, ...
它从不等于 1 的数字 d 开始，序列的第 n+1 项是对第 n 项的描述。比如第 2 项表示第 1 项有 1 个 d，所以就是 d1；第 2 项是 1 个 d（对应 d1）和 1 个 1（对应 11），所以第 3 项就是 d111。又比如第 4 项是 d113，其描述就是 1 个 d，2 个 1，1 个 3，所以下一项就是 d11231。当然这个定义对 d = 1 也成立。本题要求你推算任意给定数字 d 的外观数列的第 N 项。

输入格式：
输入第一行给出 [0,9] 范围内的一个整数 d、以及一个正整数 N（≤ 40），用空格分隔。

输出格式：
在一行中给出数字 d 的外观数列的第 N 项。

输入样例：
1 8
输出样例：
1123123111
*/
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

string generate(string &s) {
    stringstream sstream;
    char c = s[0];
    int count = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == c)
            count++;
        else {
            sstream << c << count;
            c = s[i];
            count = 1;
        }
    }
    sstream << c << count;
    return sstream.str();
}

int main(int argc, char const *argv[]) {
    string s;
    int n;
    cin >> s >> n;
    n -= 1;
    while (n--)
        s = generate(s);

    cout << s << endl;

    return 0;
}
