/*
1052 卖个萌 （20 分）
萌萌哒表情符号通常由“手”、“眼”、“口”三个主要部分组成。简单起见，我们假设一个表情符号是按下列格式输出的：

[左手]([左眼][口][右眼])[右手]
现给出可选用的符号集合，请你按用户的要求输出表情。

输入格式：
输入首先在前三行顺序对应给出手、眼、口的可选符号集。每个符号括在一对方括号 []内。题目保证每个集合都至少有一个符号，并不超过 10 个符号；每个符号包含 1 到 4 个非空字符。

之后一行给出一个正整数 K，为用户请求的个数。随后 K 行，每行给出一个用户的符号选择，顺序为左手、左眼、口、右眼、右手——这里只给出符号在相应集合中的序号（从 1 开始），数字间以空格分隔。

输出格式：
对每个用户请求，在一行中输出生成的表情。若用户选择的序号不存在，则输出 Are you kidding me? @\/@。

输入样例：
[╮][╭][o][~\][/~]  [<][>]
 [╯][╰][^][-][=][>][<][@][⊙]
[Д][▽][_][ε][^]  ...
4
1 1 2 2 2
6 8 1 5 5
3 3 4 3 3
2 10 3 9 3
输出样例：
╮(╯▽╰)╭
<(@Д=)/~
o(^ε^)o
Are you kidding me? @\/@
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void prints(vector<string> &array) {
    cout << array[0];
    for (int i = 1; i < array.size(); i++)
        cout << " " << array[i];
    cout << endl;
}

int main(int argc, char const *argv[]) {
    vector<string> hand, eye, mouth;

    string s;
    int pos = 0;
    getline(cin, s);
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '[')
            pos = i;
        if (s[i] == ']')
            hand.push_back(s.substr(pos + 1, i - pos - 1));
    }
    getline(cin, s);
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '[')
            pos = i;
        if (s[i] == ']')
            eye.push_back(s.substr(pos + 1, i - pos - 1));
    }
    getline(cin, s);
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '[')
            pos = i;
        if (s[i] == ']')
            mouth.push_back(s.substr(pos + 1, i - pos - 1));
    }

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int num[5];
        for (int j = 0; j < 5; j++) {
            cin >> num[j];
        }
        if (num[0] > hand.size() || num[4] > hand.size() ||
            num[1] > eye.size() || num[3] > eye.size() ||
            num[2] > mouth.size() || num[0] < 1 || num[1] < 1 || num[2] < 1 ||
            num[3] < 1 || num[4] < 1) {
            printf("Are you kidding me? @\\/@\n");
        } else {
            cout << hand[num[0] - 1] << '(' << eye[num[1] - 1]
                 << mouth[num[2] - 1] << eye[num[3] - 1] << ')'
                 << hand[num[4] - 1] << endl;
        }
    }
    return 0;
}
