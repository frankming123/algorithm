#include <iostream>
#include <queue>
#include <string>

using namespace std;

struct stu {
    string id, pass;
} stus[1000];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> stus[i].id >> stus[i].pass;

    queue<stu> q;
    for (int i = 0; i < n; i++) {
        bool flag = false;
        string str = stus[i].pass;
        //printf("str: %s id: %s pass: %s\n", str.c_str(), stus[i].id.c_str(), stus[i].pass.c_str());
        for (int j = 0; j < str.length(); j++) {
            if (str[j] == '1') {
                str.replace(j, 1, 1, '@');
                flag = true;
            }
            if (str[j] == '0') {
                str.replace(j, 1, 1, '%');
                flag = true;
            }
            if (str[j] == 'l') {
                str.replace(j, 1, 1, 'L');
                flag = true;
            }
            if (str[j] == 'O') {
                str.replace(j, 1, 1, 'o');
                flag = true;
            }
        }
        if (flag)
            q.push(stu{stus[i].id, str});
    }
    if (q.empty()) {
        printf("There %s %d account%s and no account is modified", n == 1 ? "is" : "are", n, n == 1 ? "" : "s");
        return 0;
    }
    cout << q.size() << endl;
    while (!q.empty()) {
        stu s = q.front();
        q.pop();
        cout << s.id << " " << s.pass << endl;
    }
    return 0;
}