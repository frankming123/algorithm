/*
1075 链表元素分类 （25 分）
给定一个单链表，请编写程序将链表元素进行分类排列，使得所有负值元素都排在非负值元素的前面，而
[0, K] 区间内的元素都排在大于 K
的元素前面。但每一类内部元素的顺序是不能改变的。例如：给定链表为
18→7→-4→0→5→-6→10→11→-2，K 为 10，则输出应该为 -4→-6→-2→7→0→5→10→18→11。

输入格式：
每个输入包含一个测试用例。每个测试用例第 1 行给出：第 1
个结点的地址；结点总个数，即正整数N (≤10 ​5 ​​ )；以及正整数K
(≤103)。结点的地址是 5 位非负整数，NULL 地址用 −1 表示。

接下来有 N 行，每行格式为：

Address Data Next
其中 Address 是结点地址；Data 是该结点保存的数据，为 [−105,105]
区间内的整数；Next 是下一结点的地址。题目保证给出的链表不为空。

输出格式：
对每个测试用例，按链表从头到尾的顺序输出重排后的结果链表，其上每个结点占一行，格式与输入相同。

输入样例：
00100 9 10
23333 10 27777
00000 0 99999
00100 18 12309
68237 -6 23333
33218 -4 00000
48652 -2 -1
99999 5 68237
27777 11 48652
12309 7 33218
输出样例：
33218 -4 68237
68237 -6 48652
48652 -2 12309
12309 7 00000
00000 0 99999
99999 5 23333
23333 10 00100
00100 18 27777
27777 11 -1
*/
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {
    int root, n, k;
    cin >> root >> n >> k;
    int value[100000], next[100000];

    while (n--) {
        int addr;
        cin >> addr;
        cin >> value[addr] >> next[addr];
    }

    vector<int> negative, nomorethank, other;
    int node = root;
    while (node != -1) {
        if (value[node] < 0)
            negative.push_back(node);
        else if (value[node] <= k)
            nomorethank.push_back(node);
        else
            other.push_back(node);
        node = next[node];
    }

    for (int i = 0; i < negative.size(); i++) {
        if (i == negative.size() - 1) {
            printf("%05d %d ", negative[negative.size() - 1],
                   value[negative[negative.size() - 1]]);
            if (nomorethank.size())
                printf("%05d\n", nomorethank[0]);
            else if (other.size())
                printf("%05d\n", other[0]);
            else
                printf("-1\n");
        } else
            printf("%05d %d %05d\n", negative[i], value[negative[i]],
                   negative[i + 1]);
    }

    for (int i = 0; i < nomorethank.size(); i++) {
        if (i == nomorethank.size() - 1) {
            printf("%05d %d ", nomorethank[nomorethank.size() - 1],
                   value[nomorethank[nomorethank.size() - 1]]);
            if (other.size())
                printf("%05d\n", other[0]);
            else
                printf("-1\n");
        } else
            printf("%05d %d %05d\n", nomorethank[i], value[nomorethank[i]],
                   nomorethank[i + 1]);
    }
    for (int i = 0; i < other.size(); i++) {
        if (i == other.size() - 1) {
            printf("%05d %d -1\n", other[other.size() - 1],
                   value[other[other.size() - 1]]);
        } else
            printf("%05d %d %05d\n", other[i], value[other[i]], other[i + 1]);
    }
    return 0;
}
