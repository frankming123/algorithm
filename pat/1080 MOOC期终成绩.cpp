/*
1080 MOOC期终成绩 （25 分）
对于在中国大学MOOC（http://www.icourse163.org/ ）学习“数据结构”课程的学生，想要获得一张合格证书，必须首先获得不少于200分的在线编程作业分，然后总评获得不少于60分（满分100）。总评成绩的计算公式为 G=(G
​mid−term
​​ ×40%+G
​final
​​ ×60%)，如果 G
​mid−term
​​ >G
​final
​​ ；否则总评 G 就是 G
​final
​​ 。这里 G
​mid−term
​​  和 G
​final
​​  分别为学生的期中和期末成绩。

现在的问题是，每次考试都产生一张独立的成绩单。本题就请你编写程序，把不同的成绩单合为一张。

输入格式：
输入在第一行给出3个整数，分别是 P（做了在线编程作业的学生数）、M（参加了期中考试的学生数）、N（参加了期末考试的学生数）。每个数都不超过10000。

接下来有三块输入。第一块包含 P 个在线编程成绩 G
​p
​​ ；第二块包含 M 个期中考试成绩 G
​mid−term
​​ ；第三块包含 N 个期末考试成绩 G
​final
​​ 。每个成绩占一行，格式为：学生学号 分数。其中学生学号为不超过20个字符的英文字母和数字；分数是非负整数（编程总分最高为900分，期中和期末的最高分为100分）。

输出格式：
打印出获得合格证书的学生名单。每个学生占一行，格式为：

学生学号 G
​p
​​  G
​mid−term
​​  G
​final
​​  G

如果有的成绩不存在（例如某人没参加期中考试），则在相应的位置输出“−1”。输出顺序为按照总评分数（四舍五入精确到整数）递减。若有并列，则按学号递增。题目保证学号没有重复，且至少存在1个合格的学生。

输入样例：
6 6 7
01234 880
a1903 199
ydjh2 200
wehu8 300
dx86w 220
missing 400
ydhfu77 99
wehu8 55
ydjh2 98
dx86w 88
a1903 86
01234 39
ydhfu77 88
a1903 66
01234 58
wehu8 84
ydjh2 82
missing 99
dx86w 81
输出样例：
missing 400 -1 99 99
ydjh2 200 98 82 88
dx86w 220 88 81 84
wehu8 300 55 84 84
*/
#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

struct stu {
    string bango;
    int gp;
    int gm;
    int gf;
    int g;
};

bool arrsort(stu &a, stu &b) {
    if (a.g > b.g)
        return true;
    else if (a.g == b.g && a.bango < b.bango)
        return true;
    return false;
}

int main(int argc, char const *argv[]) {
    int p, m, n;
    map<string, stu> grade;
    cin >> p >> m >> n;
    string s;
    int g;
    for (int i = 0; i < p; i++) {
        cin >> s >> g;
        if (g >= 200)
            grade[s] = stu{s, g, -1, -1, 0};
    }
    for (int i = 0; i < m; i++) {
        cin >> s >> g;
        map<string, stu>::iterator it = grade.find(s);
        if (it != grade.end())
            grade[s].gm = g;
    }
    for (int i = 0; i < n; i++) {
        cin >> s >> g;
        map<string, stu>::iterator it = grade.find(s);
        if (it != grade.end())
            grade[s].gf = g;
    }

    vector<stu> array;
    for (map<string, stu>::iterator it = grade.begin(); it != grade.end(); it++)
        array.push_back((*it).second);

    for (int i = 0; i < array.size(); i++) {
        if (array[i].gf == -1) {
            array.erase(array.begin() + i);
            i--;
        } else if (array[i].gm > array[i].gf) {
            array[i].g = 0.4 * array[i].gm + 0.6 * array[i].gf + 0.5;
        } else {
            array[i].g = array[i].gf;
        }
    }

    sort(array.begin(), array.end(), arrsort);

    for (int i = 0; i < array.size() && array[i].g >= 60; i++) {
        cout << array[i].bango << " " << array[i].gp << " " << array[i].gm
             << " " << array[i].gf << " " << array[i].g << endl;
    }

    return 0;
}
