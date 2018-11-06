/*
1065 单身狗 （25 分）
“单身狗”是中文对于单身人士的一种爱称。本题请你从上万人的大型派对中找出落单的客人，以便给予特殊关爱。

输入格式：
输入第一行给出一个正整数 N（≤ 50 000），是已知夫妻/伴侣的对数；随后 N 行，每行给出一对夫妻/伴侣——为方便起见，每人对应一个 ID 号，为 5 位数字（从 00000 到 99999），ID 间以空格分隔；之后给出一个正整数 M（≤ 10 000），为参加派对的总人数；随后一行给出这 M 位客人的 ID，以空格分隔。题目保证无人重婚或脚踩两条船。

输出格式：
首先第一行输出落单客人的总人数；随后第二行按 ID 递增顺序列出落单的客人。ID 间用 1 个空格分隔，行的首尾不得有多余空格。

输入样例：
3
11111 22222
33333 44444
55555 66666
7
55555 44444 10000 88888 22222 11111 23333
输出样例：
5
10000 23333 44444 55555 88888
*/
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
    int n;
    cin >> n;
    int array[100000] = {0};
    for (int i = 0; i < 100000; i++)
        array[i] = -1;
    bool singledog[100000] = {false};

    for (int i = 0; i < n; i++) {
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        array[tmp1] = tmp2;
        array[tmp2] = tmp1;
    }

    cin >> n;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        if (array[tmp] == -1)
            singledog[tmp] = true;
        else if (singledog[array[tmp]])
            singledog[array[tmp]] = false;
        else
            singledog[tmp] = true;
    }

    int sum = 0;
    for (int i = 0; i < 100000; i++)
        if (singledog[i])
            sum++;
    printf("%d\n", sum);

    bool flag = false;
    for (int i = 0; i < 100000; i++)
        if (singledog[i]) {
            printf("%s%05d", flag ? " " : "", i);
            flag = true;
        }
    return 0;
}
