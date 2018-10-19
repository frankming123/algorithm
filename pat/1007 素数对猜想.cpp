/*
1007 素数对猜想 （20 分）
让我们定义d​n为：dn=pn+1−pn，其中pi是第i个素数。显然有d1=1，且对于n>1有dn是偶数。“素数对猜想”认为“存在无穷多对相邻且差为2的素数”。

现给定任意正整数N(<105)，请计算不超过N的满足猜想的素数对的个数。

输入格式:
输入在一行给出正整数N。

输出格式:
在一行中输出不超过N的满足猜想的素数对的个数。

输入样例:
20
输出样例:
4
*/

#include <cmath>
#include <iostream>

using namespace std;

bool issu(int n) {
    int nsqrt = int(sqrt(double(n)));
    for (int i = 2; i <= nsqrt; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {

    int n, number, nums = 0;
    cin >> n;
    for (int i = n; i >= 2; i--) {
        if (issu(i)) {
            if (number - i == 2) {
                nums++;
            }
            number = i;
        }
    }
    cout << nums;
    return 0;
}