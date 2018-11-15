/*
1038 统计同成绩学生 （20 分）
本题要求读入 N 名学生的成绩，将获得某一给定分数的学生人数输出。

输入格式：
输入在第 1 行给出不超过 10
​5
​​  的正整数 N，即学生总人数。随后一行给出 N 名学生的百分制整数成绩，中间以空格分隔。最后一行给出要查询的分数个数 K（不超过 N 的正整数），随后是 K 个分数，中间以空格分隔。

输出格式：
在一行中按查询顺序给出得分等于指定分数的学生人数，中间以空格分隔，但行末不得有多余空格。

输入样例：
10
60 75 90 55 75 99 82 90 75 50
3 75 90 88
输出样例：
3 2 0
*/
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
    int n;
    scanf("%d", &n);
    char *grades = new char[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &grades[i]);

    int m;
    scanf("%d", &m);
    char *snum = new char[m];
    int num[101] = {0};
    for (int i = 0; i < m; i++)
        scanf("%d", &snum[i]);

    for (int i = 0; i < n; i++) {
        num[grades[i]]++;
    }

    printf("%d", num[snum[0]]);
    for (int i = 1; i < m; i++) {
        printf(" %d", num[snum[i]]);
    }
    delete grades;
    delete snum;
    return 0;
}
