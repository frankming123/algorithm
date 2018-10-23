/*
1017 A除以B （20 分）
本题要求计算 A/B，其中 A 是不超过 1000 位的正整数，B 是 1 位正整数。你需要输出商数 Q 和余数 R，使得 A=B×Q+R 成立。

输入格式：
输入在一行中依次给出 A 和 B，中间以 1 空格分隔。

输出格式：
在一行中依次输出 Q 和 R，中间以 1 空格分隔。

输入样例：
123456789050987654321 7
输出样例：
17636684150141093474 3
*/
#include <iostream>
#include <string>
using namespace std;
int main() {
    string a;
    int b;
    cin >> a >> b;
    int t, temp;
    int lena = a.length();
    t = (a[0] - '0') / b;                    //商
    if (lena == 1 || (t != 0 && lena > 1)) { //分为长度为1或大于1两种情况
        cout << t;
    }
    temp = (a[0] - '0') % b; //余数
    for (int i = 1; i < lena; i++) {
        t = ((temp * 10) + a[i] - '0') / b;
        cout << t;
        temp = ((temp * 10) + a[i] - '0') % b;
    }
    cout << " " << temp;
    return 0;
}