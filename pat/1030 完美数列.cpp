/*
1030 完美数列 （25 分）
给定一个正整数数列，和正整数 p，设这个数列中的最大值是 M，最小值是 m，如果
M≤mp，则称这个数列是完美数列。

现在给定参数 p 和一些正整数，请你从中选择尽可能多的数构成一个完美数列。

输入格式：
输入第一行给出两个正整数 N 和 p，其中 N（≤10
​5）是输入的正整数的个数，p（≤109）是给定的参数。第二行给出
N 个正整数，每个数不超过 109 ​​ 。

输出格式：
在一行中输出最多可以选择多少个数可以用它们组成一个完美数列。

输入样例：
10 8
2 3 20 4 5 1 6 7 8 9
输出样例：
8
*/
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool isRight(long a, long b, long p) {
    if (a <= b * p)
        return true;
    return false;
}

int main() {
    long n, p;
    cin >> n >> p;
    vector<long> array(n);
    for (int i = 0; i < n; i++) {
        cin >> array[i];
    }
    sort(array.begin(), array.begin() + n);
    int maxnum = 1;
    for (int i = 0; i <= array.size() - maxnum; i++) {
        for (int j = i + maxnum; j < array.size(); j++) {
            if (isRight(array[j], array[i], p)) {
                maxnum = (j - i + 1 > maxnum) ? (j - i + 1) : maxnum;
            } else {
                break;
            }
        }
    }
    cout << maxnum << endl;
    return 0;
}