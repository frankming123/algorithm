/*
数学鬼才，才能AC
Description

你在一栋楼房下面，楼房一共有nn层，第ii层每秒有P_iP 
i
​	 的概率会扔下一个东西并立马砸到你。

求第一秒你被砸到的概率。


Input

只有一组测试数据。

第一行一个整数n(1\le n\le 10^5)n(1≤n≤10 
5
 )。

之后有nn行，第i+1i+1行有两个整数a_i,b_i(1\le a_i\le b_i\le 10^9)a 
i
​	 ,b 
i
​	 (1≤a 
i
​	 ≤b 
i
​	 ≤10 
9
 )，表示P_i=\frac {a_i}{b_i}P 
i
​	 = 
b 
i
​	 
a 
i
​	 
​	 


Output

设答案为\frac pq 
q
p
​	 ，则输出p\times q^{-1}p×q 
−1
 在模(10^9+7)(10 
9
 +7)意义时的值

也就是求p\times (qp×(q的逆元))


Sample Input 1 

2
1 2
1 2
Sample Output 1

750000006
Hint

一共只有如下状态：

1. 第一层和第二层都扔了下来

2. 第一层扔了下来

3. 第二层扔了下来

4. 第一层和第二层都没有扔下来

以上四种都是等概率发生的

除了第四种情况外，都会被砸到

因此被砸到的概率是\frac 34 
4
3
​	 ，这个值在模10^9+710 
9
 +7意义下就是750000006750000006
*/
#include <iostream>
using namespace std;

#define MOD 1000000007
#define ll long long

ll quickpow(ll a, ll b) {
    if (b == 1)
        return a;
    return quickpow(a * a % MOD, b / 2) * (b % 2 == 0 ? 1 : a) % MOD;
}

int main() {
    std::ios::sync_with_stdio(false);
    int n;
    cin >> n;
    int a, b;
    ll res = 1;
    ll zi = 1, mu = 1;
    while (n--) {
        cin >> a >> b;
        zi = zi * (b - a) % MOD;
        mu = mu * b % MOD;
        res = res * quickpow(b, MOD - 2) % MOD;
    }
    // cout << zi << " " << mu << " " << res << endl;
    res = ((mu - zi < 0) ? (MOD + mu - zi) : (mu - zi)) * res % MOD;
    // res = (mu - zi) * res % MOD;
    cout << res << endl;
}
