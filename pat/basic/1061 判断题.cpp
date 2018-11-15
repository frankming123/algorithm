/*
1061 判断题 （15 分）
判断题的评判很简单，本题就要求你写个简单的程序帮助老师判题并统计学生们判断题的得分。

输入格式：
输入在第一行给出两个不超过 100 的正整数 N 和 M，分别是学生人数和判断题数量。第二行给出 M 个不超过 5 的正整数，是每道题的满分值。第三行给出每道题对应的正确答案，0 代表“非”，1 代表“是”。随后 N 行，每行给出一个学生的解答。数字间均以空格分隔。

输出格式：
按照输入的顺序输出每个学生的得分，每个分数占一行。

输入样例：
3 6
2 1 3 3 4 5
0 0 1 0 1 1
0 1 1 0 0 1
1 0 1 0 1 0
1 1 0 0 1 1
输出样例：
13
11
12
*/
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
    int n, m;
    cin >> n >> m;

    int maxscore[m];
    bool rightanswer[m];
    for (int i = 0; i < m; i++)
        cin >> maxscore[i];
    for (int i = 0; i < m; i++)
        cin >> rightanswer[i];

    for (int i = 0; i < n; i++) {
        int score = 0;
        for (int j = 0; j < m; j++) {
            bool answer;
            cin >> answer;
            if (answer == rightanswer[j])
                score += maxscore[j];
        }
        cout << score << endl;
    }
    return 0;
}
