/*
1013 数素数 （20 分）
令 P
​i
​​  表示第 i 个素数。现任给两个正整数 M≤N≤10
​4
​​ ，请输出 P
​M
​​  到 P
​N
​​  的所有素数。

输入格式：
输入在一行中给出 M 和 N，其间以空格分隔。

输出格式：
输出从 P
​M
​​  到 P
​N
​​  的所有素数，每 10 个数字占 1 行，其间以空格分隔，但行末不得有多余空格。

输入样例：
5 27
输出样例：
11 13 17 19 23 29 31 37 41 43
47 53 59 61 67 71 73 79 83 89
97 101 103
*/
#include <climits>
#include <cmath>
#include <iostream>

using namespace std;

bool isSu(int n) {

    int sqrtn = sqrt(n);
    for (int i = 2; i <= sqrtn; i++) {
        if (n % i == 0)
            return false;
    }
    return true;
}

int main() {
    int m, n, count = 0;
    cin >> m >> n;
    long number;
    for (int i = 2; i < INT_MAX; i++) {
        if (isSu(i)) {
            count++;
            if (count > n)
                break;
            if (count < m)
                continue;
            int pos = count - m;
            if (pos % 10 == 0)
                cout << i;
            else if (pos % 10 == 9)
                cout << " " << i << endl;
            else
                cout << " " << i;
        }
    }
    return 0;
}