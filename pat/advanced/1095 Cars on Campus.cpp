#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

int n, k;

struct node {
    string id;
    int tim;
    bool in;
};
vector<node> v1, v2;

void print(vector<node> &v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i].id;
        printf(" %02d:%02d:%02d ", v[i].tim / 3600, v[i].tim / 60 % 60, v[i].tim % 60);
        cout << v[i].in << endl;
    }
}

bool cmp1(node &a, node &b) {
    if (a.id == b.id)
        return a.tim < b.tim;
    return a.id < b.id;
}
bool cmp2(node &a, node &b) {
    return a.tim < b.tim;
}

int main() {
    cin >> n >> k;
    string id;
    int t1, t2, t3;
    string in;
    v1.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> v1[i].id;
        scanf("%d:%d:%d", &t1, &t2, &t3);
        v1[i].tim = t1 * 3600 + t2 * 60 + t3;
        cin >> in;
        v1[i].in = in[0] == 'i' ? true : false;
    }
    sort(v1.begin(), v1.end(), cmp1);
    map<string, int> mmap;
    for (int i = 0; i < v1.size() - 1; i++) {
        if (v1[i].id == v1[i + 1].id && v1[i].in && !v1[i + 1].in) {
            v2.push_back(v1[i]);
            v2.push_back(v1[i + 1]);
            if (mmap.find(v1[i].id) != mmap.end())
                mmap[v1[i].id] += v1[i + 1].tim - v1[i].tim;
            else
                mmap[v1[i].id] = v1[i + 1].tim - v1[i].tim;
        }
    }
    sort(v2.begin(), v2.end(), cmp2);
    vector<int> path(v2.size());
    path[0] = 1;
    for (int i = 1; i < path.size(); i++) {
        if (v2[i].in)
            path[i] = path[i - 1] + 1;
        else
            path[i] = path[i - 1] - 1;
    }
    int i = 0;
    int tim;
    while (k--) {
        scanf("%d:%d:%d", &t1, &t2, &t3);
        tim = t1 * 3600 + t2 * 60 + t3;
        while (i < v2.size() && v2[i].tim <= tim)
            i++;
        if (i == 0)
            cout << 0 << endl;
        else
            cout << path[i - 1] << endl;
    }
    tim = 0;
    vector<string> res;
    for (map<string, int>::iterator it = mmap.begin(); it != mmap.end(); it++) {
        if (it->second > tim) {
            res.clear();
            res.push_back(it->first);
            tim = it->second;
        } else if (it->second == tim)
            res.push_back(it->first);
    }

    sort(res.begin(), res.end());
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << " ";

    printf("%02d:%02d:%02d", tim / 3600, tim / 60 % 60, tim % 60);
    return 0;
}