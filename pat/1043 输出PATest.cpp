/*
1043 输出PATest （20 分）
给定一个长度不超过 10
​4
​​  的、仅由英文字母构成的字符串。请将字符重新调整顺序，按 PATestPATest.... 这样的顺序输出，并忽略其它字符。当然，六种字符的个数不一定是一样多的，若某种字符已经输出完，则余下的字符仍按 PATest 的顺序打印，直到所有字符都被输出。

输入格式：
输入在一行中给出一个长度不超过 10
​4
​​  的、仅由英文字母构成的非空字符串。

输出格式：
在一行中按题目要求输出排序后的字符串。题目保证输出非空。

输入样例：
redlesPayBestPATTopTeePHPereatitAPPT
输出样例：
PATestPATestPTetPTePePee
*/
#include <iostream>
#include <string>

using namespace std;

int array[6];

bool isEmpty() {
    for (int i = 0; i < 6; i++)
        if (array[i] != 0)
            return false;
    return true;
}

int main(int argc, char const *argv[]) {
    string s;
    getline(cin, s);
    for (int i = 0; i < s.length(); i++) {
        switch (s[i]) {
        case 'P':
            array[0]++;
            break;
        case 'A':
            array[1]++;
            break;
        case 'T':
            array[2]++;
            break;
        case 'e':
            array[3]++;
            break;
        case 's':
            array[4]++;
            break;
        case 't':
            array[5]++;
            break;
        }
    }

    while (!isEmpty()) {
        for (int i = 0; i < 6; i++) {
            if (array[i] != 0) {
                if (i == 0)
                    printf("P");
                if (i == 1)
                    printf("A");
                if (i == 2)
                    printf("T");
                if (i == 3)
                    printf("e");
                if (i == 4)
                    printf("s");
                if (i == 5)
                    printf("t");
                array[i]--;
            }
        }
    }
    return 0;
}
