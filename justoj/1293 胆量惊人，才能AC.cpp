/*
胆量惊人，才能AC
Description

设A为11~nn的全排列，则第ii项为A_iA 
i
​	 。

设f(A)=A_1^{A_2^{A_3^{......^{A_n}}}}f(A)=A 
1
A 
2
A 
3
...... 
A 
n
​	 
 
​	 
​	 
​	 

换句话说

f(A_1,A_2,A_3,...,A_n) = \begin{cases} A_1, & \text{$n=1$} \\ A_1^{f(A_2,A_3,...,A_n)} & \text{$n>1$} \end{cases}f(A 
1
​	 ,A 
2
​	 ,A 
3
​	 ,...,A 
n
​	 )={ 
A 
1
​	 ,
A 
1
f(A 
2
​	 ,A 
3
​	 ,...,A 
n
​	 )
​	 
​	  
n=1
n>1
​	 


求11~nn的全排列的f的和。

答案对22取模。


Input

共有T(1\le T\le 10^6)T(1≤T≤10 
6
 )组测试数据。

只有一行n(1\le n\le 10^9)n(1≤n≤10 
9
 )。


Output

输出答案，记得对2取模。


Sample Input 1 

1
3
Sample Output 1

0
*/
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
    std::ios::sync_with_stdio(false);
    int t;
    cin >> t;
    int n;
    while (t--) {
        cin >> n;
        if (n <= 2)
            cout << 1 << endl;
        else
            cout << 0 << endl;
    }
    return 0;
}
