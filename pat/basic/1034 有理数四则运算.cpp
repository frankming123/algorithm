/*
1034 有理数四则运算 （20 分）
本题要求编写程序，计算 2 个有理数的和、差、积、商。

输入格式：
输入在一行中按照 a1/b1 a2/b2 的格式给出两个分数形式的有理数，其中分子和分母全是整型范围内的整数，负号只可能出现在分子前，分母不为 0。

输出格式：
分别在 4 行中按照 有理数1 运算符 有理数2 = 结果 的格式顺序输出 2 个有理数的和、差、积、商。注意输出的每个有理数必须是该有理数的最简形式 k a/b，其中 k 是整数部分，a/b 是最简分数部分；若为负数，则须加括号；若除法分母为 0，则输出 Inf。题目保证正确的输出中没有超过整型范围的整数。

输入样例 1：
2/3 -4/2
输出样例 1：
2/3 + (-2) = (-1 1/3)
2/3 - (-2) = 2 2/3
2/3 * (-2) = (-1 1/3)
2/3 / (-2) = (-1/3)
输入样例 2：
5/3 0/6
输出样例 2：
1 2/3 + 0 = 1 2/3
1 2/3 - 0 = 1 2/3
1 2/3 * 0 = 0
1 2/3 / 0 = Inf
*/
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

long num[4];
long add[2];
long sub[2];
long mul[2];
long divide[2];

void addnum() {
    add[0] = num[0] * num[3] + num[1] * num[2];
    add[1] = num[1] * num[3];
}
void subnum() {
    sub[0] = num[0] * num[3] - num[1] * num[2];
    sub[1] = num[1] * num[3];
}
void mulnum() {
    mul[0] = num[0] * num[2];
    mul[1] = num[1] * num[3];
}
void divnum() {
    divide[0] = num[0] * num[3];
    divide[1] = num[1] * num[2];
}
void calc() {
    addnum();
    subnum();
    mulnum();
    divnum();
}

long gcd(long a, long b) {
    long r;
    while ((r = a % b)) {
        a = b;
        b = r;
    }
    return b;
}

string simple(long a, long b) {
    if (b == 0)
        return "Inf";
    if (a == 0)
        return "0";
    bool isNeg = false;
    if (a < 0 && b > 0) {
        isNeg = true;
        a = -a;
    } else if (a > 0 && b < 0) {
        isNeg = true;
        b = -b;
    } else if (a < 0 && b < 0) {
        a = -a;
        b = -b;
    }
    long tmp = gcd(a, b);

    a /= tmp;
    b /= tmp;
    long extra = a / b;

    stringstream ss;
    if (isNeg)
        ss << "-";
    if (extra && a % b)
        ss << extra << " " << (a % b) << "/" << b;
    else if (extra)
        ss << extra;
    else if (a % b)
        ss << (a % b) << "/" << b;

    if (isNeg)
        return "(" + ss.str() + ")";
    return ss.str();
}

int main() {
    scanf("%ld/%ld", &num[0], &num[1]);
    scanf("%ld/%ld", &num[2], &num[3]);

    calc();

    string num1 = simple(num[0], num[1]), num2 = simple(num[2], num[3]);

    cout << num1 << " + " << num2 << " = " << simple(add[0], add[1]) << endl;
    cout << num1 << " - " << num2 << " = " << simple(sub[0], sub[1]) << endl;
    cout << num1 << " * " << num2 << " = " << simple(mul[0], mul[1]) << endl;
    cout << num1 << " / " << num2 << " = " << simple(divide[0], divide[1])
         << endl;
    return 0;
}