/*
1086 就不告诉你 （15 分）
做作业的时候，邻座的小盆友问你：“五乘以七等于多少？”你应该不失礼貌地围笑着告诉他：“五十三。”本题就要求你，对任何一对给定的正整数，倒着输出它们的乘积。

53.jpg

输入格式：
输入在第一行给出两个不超过 1000 的正整数 A 和 B，其间以空格分隔。

输出格式：
在一行中倒着输出 A 和 B 的乘积。

输入样例：
5 7
输出样例：
53
*/
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
    int a, b;
    cin >> a >> b;
    int res = a * b;
    bool flag = false;

    while (res != 0) {
        int tmp = res % 10;
        if (tmp != 0)
            flag = true;
        res = res / 10;
        if (flag)
            printf("%d", tmp);
    }

    return 0;
}
