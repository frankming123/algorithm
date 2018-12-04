/*
回文子串
Description

回文串：如果某字符串从头读到尾和从尾读到头是一样的，则称其为回文串。

如”aabaa”,”acca”,而”abcd”不是。

子串：如果A是B的子串，则A可以由B的开头去掉一定数量字符，结尾去掉一定数量字符（数量可以为0）得到。

如"abc", "ab",和 "c" 是"abc"的子串,而"ac" 和"d"不是.

回文子串：当某子串是回文串时，则称为回文子串。

现在给出一个字符串，你可以任意重新排列它的字符顺序。

求在所有重排字符串里，其回文子串的最大数量。


Input

只有一组数据。

第一行为nn，即字符串共有nn个字符。 (1 \le n \le 10^6)(1≤n≤10 
6
 )

第二行为字符串ss. (|s|=n)(∣s∣=n)

保证所有字符都是小写字母。


Output

输出答案。


Sample Input 1 

5
oolol
Sample Output 1

9
Sample Input 2 

16
gagadbcgghhchbdf
Sample Output 2

29
Hint

在第一个样例里：

“oolol”可以重排列为”ololo”,此时共有9个子串是回文串，分别是"o", "l", "o", "l", "o", "olo", "lol", "olo", "ololo". 
*/
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
    int n;
    scanf("%d\n", &n);
    int appears[26] = {0};
    while (n--) {
        appears[getchar() - 'a']++;
    }

    long long res = 0;
    for (int i = 0; i < 26; i++)
        res += appears[i] * (appears[i] + 1) / 2;

    printf("%lld\n", res);
    return 0;
}
