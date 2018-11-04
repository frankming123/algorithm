/*
1060 爱丁顿数 （25 分）
英国天文学家爱丁顿很喜欢骑车。据说他为了炫耀自己的骑车功力，还定义了一个“爱丁顿数”
E ，即满足有 E 天骑车超过 E 英里的最大整数 E。据说爱丁顿自己的 E 等于87。

现给定某人 N 天的骑车距离，请你算出对应的爱丁顿数 E（≤N）。

输入格式：
输入第一行给出一个正整数 N (≤105)，即连续骑车的天数；第二行给出 N
个非负整数，代表每天的骑车距离。

输出格式：
在一行中给出 N 天的爱丁顿数。

输入样例：
10
6 7 6 9 3 10 8 2 7 8
输出样例：
6
*/
#include <algorithm>
#include <iostream>

using namespace std;

bool isLarger(int a, int b) { return a > b; }

int main(int argc, char const *argv[]) {
    int n;
    cin >> n;
    int *array = new int[n]{0};
    for (int i = 0; i < n; i++)
        cin >> array[i];
    sort(array, array + n, isLarger);

    int i = 0;
    while (i < n && array[i] > i + 1)
        i++;
    printf("%d", i);
    return 0;
}
