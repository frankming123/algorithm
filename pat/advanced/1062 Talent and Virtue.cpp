#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct stu {
    string id;
    int virute;
    int talent;
};
bool cmp(stu &a, stu &b) {
    if ((a.virute + a.talent) > (b.virute + b.talent))
        return true;
    if (((a.virute + a.talent) == (b.virute + b.talent)) && (a.virute > b.virute))
        return true;
    if (a.virute == b.virute && a.talent == b.talent)
        return a.id < b.id;
    return false;
}

void print(vector<stu> &v) {
    for (int i = 0; i < v.size(); i++)
        cout << v[i].id << " " << v[i].virute << " " << v[i].talent << endl;
}
int main() {
    std::ios::sync_with_stdio(false);
    int n, l, h;
    cin >> n >> l >> h;

    stu stus[n];
    vector<stu> stu1, stu2, stu3, stu4;
    string id;
    int virute, talent;
    for (int i = 0; i < n; i++) {
        cin >> id >> virute >> talent;
        if (virute < l || talent < l)
            continue;
        stu tmp = {id, virute, talent};
        if (virute >= h && talent >= h)
            stu1.push_back(tmp);
        else if (virute >= h && talent < h)
            stu2.push_back(tmp);
        else if (virute < h && talent < h && virute >= talent)
            stu3.push_back(tmp);
        else
            stu4.push_back(tmp);
    }
    sort(stu1.begin(), stu1.end(), cmp);
    sort(stu2.begin(), stu2.end(), cmp);
    sort(stu3.begin(), stu3.end(), cmp);
    sort(stu4.begin(), stu4.end(), cmp);
    cout << (stu1.size() + stu2.size() + stu3.size() + stu4.size()) << endl;
    print(stu1);
    print(stu2);
    print(stu3);
    print(stu4);
    return 0;
}