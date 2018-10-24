/*
1028 人口普查 （20 分）
某城镇进行人口普查，得到了全体居民的生日。现请你写个程序，找出镇上最年长和最年轻的人。

这里确保每个输入的日期都是合法的，但不一定是合理的——假设已知镇上没有超过 200 岁的老人，而今天是 2014 年 9 月 6 日，所以超过 200 岁的生日和未出生的生日都是不合理的，应该被过滤掉。

输入格式：
输入在第一行给出正整数 N，取值在(0,10
​5
​​ ]；随后 N 行，每行给出 1 个人的姓名（由不超过 5 个英文字母组成的字符串）、以及按 yyyy/mm/dd（即年/月/日）格式给出的生日。题目保证最年长和最年轻的人没有并列。

输出格式：
在一行中顺序输出有效生日的个数、最年长人和最年轻人的姓名，其间以空格分隔。

输入样例：
5
John 2001/05/12
Tom 1814/09/06
Ann 2121/01/30
James 1814/09/05
Steve 1967/11/20
输出样例：
3 Tom John
*/
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

struct birth {
    string name;
    int year;
    int month;
    int day;
} array[100000];

bool isOlder(birth &a, birth &b) {
    if (a.year < b.year || (a.year == b.year && a.month < b.month) ||
        (a.year == b.year && a.month == b.month && a.day < b.day))
        return true;
    return false;
}

int main() {
    int n, num = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string tmp1;
        int tmp2, tmp3, tmp4;
        cin >> tmp1;
        scanf("%d/%d/%d", &tmp2, &tmp3, &tmp4);
        if (tmp2 > 2014 || tmp2 < 1814 || (tmp2 == 2014 && tmp3 > 9) ||
            (tmp2 == 2014 && tmp3 == 9 && tmp4 > 6) ||
            (tmp2 == 1814 && tmp3 < 9) ||
            (tmp2 == 1814 && tmp3 == 9 && tmp4 < 6)) {
            continue;
        }
        array[num].name = tmp1;
        array[num].year = tmp2;
        array[num].month = tmp3;
        array[num].day = tmp4;
        num++;
    }

    sort(array, array + num, isOlder);
    if (num)
        cout << num << " " << array[0].name << " " << array[num - 1].name;
    else
        cout << "0";
    return 0;
}