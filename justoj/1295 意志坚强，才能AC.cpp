/*
意志坚强，才能AC
Description

“生活就像海洋，只有意志坚强的人才能到达彼岸。”

如同这句话，假设你的ACMACM生涯里的AccptedAccpted用11表示，而Wrong AnswerWrongAnswer用00表示。

意志坚强的你能够将最多kk个Wrong AnswerWrongAnswer变为AccptedAccpted。

那你的ACMACM生涯中，连续一段全是AcceptedAccepted的长度最多能为多少？


Input

只有一组测试数据。

第一行为n(1\le n \le 10^6),k(1\le k \le n)n(1≤n≤10 
6
 ),k(1≤k≤n),表示ACMACM生涯刷题数量为nn，以及最多kk次变换。

第二行为长度为nn的，只含有0,10,1的字符串。


Output

输出答案。


Sample Input 1 

11 1
1 1 0 0 1 1 1 1 0 1 1
Sample Output 1

7
*/
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
    int n, k;
    cin >> n >> k;
    int array[n];
    for (int i = 0; i < n; i++)
        cin >> array[i];
    int l = 0, r = 0;
    int maxlen = 0;
    while (r < n) {
        if (array[r] == 1) {
            maxlen = (r - l + 1) > maxlen ? (r - l + 1) : maxlen;
            // printf("l:%d r:%d len:%d\n", l, r, maxlen);
            r++;
        } else {
            // printf("k:%d l:%d r:%d len:%d\n", k, l, r, maxlen);
            if (k > 0) {
                maxlen = (r - l + 1) > maxlen ? (r - l + 1) : maxlen;
                k--;
                r++;
            } else {
                while (array[l] != 0)
                    l++;
                l++;
                r++;
            }
        }
    }
    cout << maxlen << endl;
    return 0;
}
