/*
1062 最简分数 （20 分）
一个分数一般写成两个整数相除的形式：N/M，其中 M 不为0。最简分数是指分子和分母没有公约数的分数表示形式。

现给定两个不相等的正分数 N
​1
​​ /M
​1
​​  和 N
​2
​​ /M
​2
​​ ，要求你按从小到大的顺序列出它们之间分母为 K 的最简分数。

输入格式：
输入在一行中按 N/M 的格式给出两个正分数，随后是一个正整数分母 K，其间以空格分隔。题目保证给出的所有整数都不超过 1000。

输出格式：
在一行中按 N/M 的格式列出两个给定分数之间分母为 K 的所有最简分数，按从小到大的顺序，其间以 1 个空格分隔。行首尾不得有多余空格。题目保证至少有 1 个输出。

输入样例：
7/18 13/20 12
输出样例：
5/12 7/12
*/
#include <iostream>

using namespace std;

long GCD(long a, long b) { return b == 0 ? a : GCD(b, a % b); }

int main(int argc, char const *argv[]) {
    int n1, n2, m1, m2, k;
    scanf("%d/%d %d/%d %d", &n1, &n2, &m1, &m2, &k);

    if (n1 * m2 > n2 * m1) {
        swap(n1, m1);
        swap(n2, m2);
    }

    int num = 1;
    bool isfirst = true;
    while (num * n2 <= n1 * k)
        num++;
    while (num * m2 < m1 * k) {
        if (GCD(num, k) == 1)
            if (isfirst) {
                printf("%d/%d", num, k);
                isfirst = false;
            } else
                printf(" %d/%d", num, k);
        num++;
    }

    return 0;
}
