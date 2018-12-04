/*
直觉准确，才能AC
Description

给定 nn，求一对整数 (i,j)(i,j)，在满足 1\le i\le j\le n1≤i≤j≤n 且gcd(i,j)=1gcd(i,j)=1 的前提下，求Max(i+j)Max(i+j) 的值


Input

共有T(1\le T\le 10^6)T(1≤T≤10 
6
 )组测试数据。

第一行为n(1\le n\le 10^{18})n(1≤n≤10 
18
 ).


Output

输出答案。


Sample Input 1 

1
2
Sample Output 1

3
*/
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
    int t;
    cin >> t;
    unsigned long long n;
    while (t--) {
        cin >> n;
        if (n == 1)
            cout << 2 << endl;
        else
            cout << (2 * n - 1) << endl;
    }
    return 0;
}
