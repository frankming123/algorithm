/*
1087 有多少不同的值 （20 分）
当自然数 n 依次取 1、2、3、……、N 时，算式 ⌊n/2⌋+⌊n/3⌋+⌊n/5⌋ 有多少个不同的值？（注：⌊x⌋ 为取整函数，表示不超过 x 的最大自然数，即 x 的整数部分。）

输入格式：
输入给出一个正整数 N（2≤N≤10
​4
​​ ）。

输出格式：
在一行中输出题面中算式取到的不同值的个数。

输入样例：
2017
输出样例：
1480
*/
#include <iostream>

using namespace std;

bool array[10334];

int main(int argc, char const *argv[]) {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        array[i / 2 + i / 3 + i / 5] = true;
    int count = 0;
    for (int i = 0; i < 10334; i++)
        if (array[i])
            count++;
    printf("%d", count);
    return 0;
}
