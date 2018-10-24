/*
1027 打印沙漏 （20 分）
本题要求你写个程序把给定的符号打印成沙漏的形状。例如给定17个“*”，要求按下列格式打印

*****
 ***
  *
 ***
*****
所谓“沙漏形状”，是指每行输出奇数个符号；各行符号中心对齐；相邻两行符号数差2；符号数先从大到小顺序递减到1，再从小到大顺序递增；首尾符号数相等。

给定任意N个符号，不一定能正好组成一个沙漏。要求打印出的沙漏能用掉尽可能多的符号。

输入格式:
输入在一行给出1个正整数N（≤1000）和一个符号，中间以空格分隔。

输出格式:
首先打印出由给定符号组成的最大的沙漏形状，最后在一行中输出剩下没用掉的符号数。

输入样例:
19 *
输出样例:
*****
 ***
  *
 ***
*****
2
*/
#include <iostream>

using namespace std;

int heightOfx(int n, int &res) {
    if (n < 7) {
        res = n - 1;
        return 1;
    } else if (n < 17) {
        res = n - 7;
        return 2;
    }
    int height = 2, num = 7;
    while (num + (height)*4 + 2 <= n) {
        num += height * 4 + 2;
        height++;
    }
    res = n - num;
    return height;
}

int main(int argc, char const *argv[]) {
    int n, res;
    char c;
    cin >> n >> c;
    int height = heightOfx(n, res);
    for (int i = height; i >= 1; i--) {
        int count = 2 * i - 1;
        int blank = height - i;
        for (int j = 0; j < blank; j++)
            printf(" ");
        for (int j = 0; j < count; j++)
            printf("%c", c);
        printf("\n");
    }
    for (int i = 2; i <= height; i++) {
        int count = 2 * i - 1;
        int blank = height - i;
        for (int j = 0; j < blank; j++)
            printf(" ");
        for (int j = 0; j < count; j++)
            printf("%c", c);
        printf("\n");
    }
    printf("%d\n", res);
    return 0;
}
