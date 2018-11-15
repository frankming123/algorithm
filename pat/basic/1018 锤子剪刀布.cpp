/*
1018 锤子剪刀布 （20 分）
大家应该都会玩“锤子剪刀布”的游戏：两人同时给出手势，胜负规则如图所示：

FigCJB.jpg

现给出两人的交锋记录，请统计双方的胜、平、负次数，并且给出双方分别出什么手势的胜算最大。

输入格式：
输入第 1 行给出正整数 N（≤10​5），即双方交锋的次数。随后
N 行，每行给出一次交锋的信息，即甲、乙双方同时给出的的手势。C 代表“锤子”、J
代表“剪刀”、B 代表“布”，第 1 个字母代表甲方，第 2 个代表乙方，中间有 1 个空格。

输出格式：
输出第 1、2 行分别给出甲、乙的胜、平、负次数，数字间以 1 个空格分隔。第 3
行给出两个字母，分别代表甲、乙获胜次数最多的手势，中间有 1
个空格。如果解不唯一，则输出按字母序最小的解。

输入样例：
10
C J
J B
C B
B B
B C
C C
C B
J B
B C
J J
输出样例：
5 3 2
2 3 5
B B
*/
#include <iostream>
#include <vector>

using namespace std;

struct fight {
    char jia;
    char yi;
    int record; // 1:win 2:tie 0:lose
};

int judge(char a, char b) {
    if ((a == 'C' && b == 'J') || (a == 'J' && b == 'B') ||
        (a == 'B' && b == 'C')) {
        return 1;
    } else if ((a == b)) {
        return 2;
    } else {
        return 0;
    }
}

char maxBJC(int B, int J, int C) {
    if (B >= C && B >= J)
        return 'B';
    else if (C > B && C >= J)
        return 'C';
    else
        return 'J';
}

int main() {
    int n;
    cin >> n;
    vector<fight> array(n);
    for (int i = 0; i < n; i++) {
        cin >> array[i].jia >> array[i].yi;
        array[i].record = judge(array[i].jia, array[i].yi);
    }

    int jwin = 0, jlose = 0, jtie = 0, ywin = 0, ylose = 0, ytie = 0, jc = 0,
        jj = 0, jb = 0, yc = 0, yj = 0, yb = 0;
    for (int i = 0; i < n; i++) {
        if (array[i].record == 1) {
            jwin++;
            ylose++;
            if (array[i].jia == 'C')
                jc++;
            else if (array[i].jia == 'J')
                jj++;
            else
                jb++;
        } else if (array[i].record == 0) {
            jlose++;
            ywin++;
            if (array[i].yi == 'C')
                yc++;
            else if (array[i].yi == 'J')
                yj++;
            else
                yb++;
        } else {
            jtie++;
            ytie++;
        }
    }
    printf("%d %d %d\n", jwin, jtie, jlose);
    printf("%d %d %d\n", ywin, ytie, ylose);
    printf("%c %c\n", maxBJC(jb, jj, jc), maxBJC(yb, yj, yc));
    return 0;
}