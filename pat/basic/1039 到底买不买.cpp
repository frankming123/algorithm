/*
1039 到底买不买 （20 分）
小红想买些珠子做一串自己喜欢的珠串。卖珠子的摊主有很多串五颜六色的珠串，但是不肯把任何一串拆散了卖。于是小红要你帮忙判断一下，某串珠子里是否包含了全部自己想要的珠子？如果是，那么告诉她有多少多余的珠子；如果不是，那么告诉她缺了多少珠子。

为方便起见，我们用[0-9]、[a-z]、[A-Z]范围内的字符来表示颜色。例如在图1中，第3串是小红想做的珠串；那么第1串可以买，因为包含了全部她想要的珠子，还多了8颗不需要的珠子；第2串不能买，因为没有黑色珠子，并且少了一颗红色的珠子。

figbuy.jpg

图 1

输入格式：
每个输入包含 1 个测试用例。每个测试用例分别在 2 行中先后给出摊主的珠串和小红想做的珠串，两串都不超过 1000 个珠子。

输出格式：
如果可以买，则在一行中输出 Yes 以及有多少多余的珠子；如果不可以买，则在一行中输出 No 以及缺了多少珠子。其间以 1 个空格分隔。

输入样例 1：
ppRYYGrrYBR2258
YrR8RrY
输出样例 1：
Yes 8
输入样例 2：
ppRYYGrrYB225
YrR8RrY
输出样例 2：
No 2
*/
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
    int num[128] = {0};
    char c;
    while ((c = getchar()) != '\n')
        num[c]++;
    while ((c = getchar()) != '\n')
        num[c]--;

    bool canBuy = true;
    int extra = 0;
    for (int i = 0; i < 128; i++) {
        if (canBuy && num[i] < 0) {
            canBuy = false;
            extra = 0;
        }
        if (canBuy)
            extra += num[i];
        if (num[i] < 0)
            extra -= num[i];
    }
    if (canBuy)
        printf("Yes ");
    else
        printf("No ");
    printf("%d", extra);
    return 0;
}
