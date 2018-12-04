/*
经济头脑，才能AC
Description

你现在看上了一支股票，而你知道其在之后nn天的价格。

如果你最多只允许完成一次交易,你能获得的最大利润是多少？


Input

只有一组测试数据。

第一行为N(2\le N\le 10^6)N(2≤N≤10 
6
 )，表示为总共有NN天。

第二行为NN个整数分别为A_1,A_2,...,A_nA 
1
​	 ,A 
2
​	 ,...,A 
n
​	 ，A_i(1\le A_i\le 10^9)A 
i
​	 (1≤A 
i
​	 ≤10 
9
 )代表第ii天的价格。


Output

输出最大利润。


Sample Input 1 

5
3 1 3 4 6
Sample Output 1

5
Hint

第二天花11买入股票，第五天卖出股票，利润为6-1=56−1=5。
*/
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
    std::ios::sync_with_stdio(false);
    int n;
    cin >> n;
    int array[n];
    for (int i = 0; i < n; i++)
        cin >> array[i];
    int minnum = array[0];
    int res = 0;
    for (int i = 1; i < n; i++) {
        minnum = array[i] < minnum ? array[i] : minnum;
        res = array[i] - minnum > res ? (array[i] - minnum) : res;
    }
    cout << res << endl;
    return 0;
}
