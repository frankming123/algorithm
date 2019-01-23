#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

struct stu {
    string id;
    string name;
    int grade;
} stus[100000];

bool cmp1(stu &a, stu &b) { return a.id < b.id; }
bool cmp2(stu &a, stu &b) {
    if (a.name < b.name)
        return true;
    if (a.name == b.name && a.id < b.id)
        return true;
    return false;
}
bool cmp3(stu &a, stu &b) {
    if (a.grade < b.grade)
        return true;
    if (a.grade == b.grade && a.id < b.id)
        return true;
    return false;
}

typedef bool (*func)(stu &, stu &);

int main(int argc, char const *argv[]) {
    std::ios::sync_with_stdio(false);
    func funcs[3] = {cmp1, cmp2, cmp3};
    int n, c;
    cin >> n >> c;
    string id, name;
    int grade;
    for (int i = 0; i < n; i++) {
        cin >> id >> name >> grade;
        stus[i] = stu{id, name, grade};
    }
    sort(stus, stus + n, funcs[c - 1]);
    for (int i = 0; i < n; i++)
        cout << stus[i].id << " " << stus[i].name << " " << stus[i].grade
             << endl;

    return 0;
}
