/*
电话公司
Description

Lele虽然超能力很强，但是没有其他人有超能力啊，所以跟他聊天的人不能用脑电波，只能使用电话。为了解决这个问题，Lele便来到了电话公司。

你偶然成为了电话公司的工作人员。一个电话号码是这样定义的：其为1111位数字，而且必须以’88’开头。现在有一个数字串，你可以通过抽取其中的部分数字去组成一个电话号码，且每个数字被使用了之后，不能再被使用。而且当两个电话号码相同时，如果他们使用的数字来源都不同，可看做两个不同的电话号码。

Lele希望他的选择越多越好，希望你能告诉他，他最多会有多少种选择。


Input

共有T组测试数据(1 \le T \le 1000)(1≤T≤1000)

第一行为nn(1 \le n \le 100)(1≤n≤100)，表示数字串的大小。

第二行为数字串。


Output

输出答案。


Sample Input 1 

3
11
00000000008
22
0011223344556677889988
11
31415926535
Sample Output 1

1
2
0
*/
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int calc(string &s) {
    int slen = s.length();
    int count8 = 0;
    for (int i = 0; i < slen; i++)
        if (s[i] == '8')
            count8++;
    return min(slen / 11, count8);
}

int main(int argc, char const *argv[]) {
    int t;
    cin >> t;
    int n;
    string s;
    while (t--) {
        cin >> n >> s;
        cout << calc(s) << endl;
    }
    return 0;
}
