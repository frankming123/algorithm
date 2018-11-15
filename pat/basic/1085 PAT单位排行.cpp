/*
1085 PAT单位排行 （25 分）
每次 PAT 考试结束后，考试中心都会发布一个考生单位排行榜。本题就请你实现这个功能。

输入格式：
输入第一行给出一个正整数 N（≤10
​5
​​ ），即考生人数。随后 N 行，每行按下列格式给出一个考生的信息：

准考证号 得分 学校
其中准考证号是由 6 个字符组成的字符串，其首字母表示考试的级别：B代表乙级，A代表甲级，T代表顶级；得分是 [0, 100] 区间内的整数；学校是由不超过 6 个英文字母组成的单位码（大小写无关）。注意：题目保证每个考生的准考证号是不同的。

输出格式：
首先在一行中输出单位个数。随后按以下格式非降序输出单位的排行榜：

排名 学校 加权总分 考生人数
其中排名是该单位的排名（从 1 开始）；学校是全部按小写字母输出的单位码；加权总分定义为乙级总分/1.5 + 甲级总分 + 顶级总分*1.5的整数部分；考生人数是该属于单位的考生的总人数。

学校首先按加权总分排行。如有并列，则应对应相同的排名，并按考生人数升序输出。如果仍然并列，则按单位码的字典序输出。

输入样例：
10
A57908 85 Au
B57908 54 LanX
A37487 60 au
T28374 67 CMU
T32486 24 hypu
A66734 92 cmu
B76378 71 AU
A47780 45 lanx
A72809 100 pku
A03274 45 hypu
输出样例：
5
1 cmu 192 2
1 au 192 3
3 pku 100 1
4 hypu 81 2
4 lanx 81 2
*/
#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

struct sch {
    string name;
    double score;
    int count;
};

void lower(string &s) {
    for (int i = 0; i < s.length(); i++)
        if (s[i] >= 'A' && s[i] <= 'Z')
            s.replace(i, 1, 1, s[i] - 'A' + 'a');
}

bool schsort(sch &a, sch &b) {
    int ascore = int(a.score), bscore = int(b.score);
    if (ascore > bscore)
        return true;
    else if (ascore == bscore && a.count < b.count)
        return true;
    else if (ascore == bscore && a.count == b.count && a.name < b.name)
        return true;
    return false;
}

int main(int argc, char const *argv[]) {
    int n;
    cin >> n;

    map<string, sch> schoolmap;

    while (n--) {
        string bango, school;
        int score;
        cin >> bango >> score >> school;
        lower(school);
        schoolmap[school].name = school;
        if (bango[0] == 'B')
            schoolmap[school].score += score / 1.5;
        if (bango[0] == 'A')
            schoolmap[school].score += score;
        if (bango[0] == 'T')
            schoolmap[school].score += score * 1.5;
        schoolmap[school].count++;
    }

    vector<sch> array;
    for (map<string, sch>::iterator it = schoolmap.begin();
         it != schoolmap.end(); it++)
        array.push_back((*it).second);
    sort(array.begin(), array.end(), schsort);

    cout << array.size() << endl;
    int count = 1;
    cout << "1"
         << " " << array[0].name << " " << int(array[0].score) << " "
         << array[0].count << endl;
    for (int i = 1; i < array.size(); i++) {
        if (int(array[i].score) == int(array[i - 1].score)) {
            cout << count << " " << array[i].name << " " << int(array[i].score)
                 << " " << array[i].count << endl;
        } else {
            cout << i + 1 << " " << array[i].name << " " << int(array[i].score)
                 << " " << array[i].count << endl;
            count = i + 1;
        }
    }

    return 0;
}
