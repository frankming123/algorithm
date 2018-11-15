/*
1051 复数乘法 （15 分）
复数可以写成 (A+Bi) 的常规形式，其中 A 是实部，B 是虚部，i 是虚数单位，满足 i
​2
​​ =−1；也可以写成极坐标下的指数形式 (R×e
​(Pi)
​​ )，其中 R 是复数模，P 是辐角，i 是虚数单位，其等价于三角形式 (R(cos(P)+isin(P))。

现给定两个复数的 R 和 P，要求输出两数乘积的常规形式。

输入格式：
输入在一行中依次给出两个复数的 R
​1
​​ , P
​1
​​ , R
​2
​​ , P
​2
​​ ，数字间以空格分隔。

输出格式：
在一行中按照 A+Bi 的格式输出两数乘积的常规形式，实部和虚部均保留 2 位小数。注意：如果 B 是负数，则应该写成 A-|B|i 的形式。

输入样例：
2.3 3.5 5.2 0.4
输出样例：
-8.68-8.23i
*/
#include <cmath>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
    double r1, p1, r2, p2;
    scanf("%lf %lf %lf %lf", &r1, &p1, &r2, &p2);

    double res1 = r1 * cos(p1) * r2 * cos(p2) - (r1 * sin(p1) * r2 * sin(p2));
    double res2 = r1 * sin(p1) * r2 * cos(p2) + r1 * cos(p1) * r2 * sin(p2);

    if (res1 < 0 && res1 + 0.005 > 0)
        printf("0.00");
    else
        printf("%.2lf", res1);
    if (res2 > 0)
        printf("+%.2lfi", res2);
    else if (res2 < 0 && res2 + 0.005 > 0)
        printf("+0.00i");
    else
        printf("%.2lfi", res2);
    return 0;
}
