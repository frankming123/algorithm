#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

struct node {
    string id;
    int online, mid, fin, score;
};

map<string, node> mmap;

bool cmp(node &a, node &b) {
    if (a.score == b.score)
        return a.id < b.id;
    return a.score > b.score;
}

int main() {
    int p, m, n;
    cin >> p >> m >> n;
    string s;
    int score;
    while (p--) {
        cin >> s >> score;
        if (score < 200)
            continue;
        mmap[s] = node{s, score, -1, 0, 0};
    }
    while (m--) {
        cin >> s >> score;
        if (mmap.find(s) != mmap.end())
            mmap[s].mid = score;
    }
    while (n--) {
        cin >> s >> score;
        if (mmap.find(s) != mmap.end())
            mmap[s].fin = score;
    }
    vector<node> v;
    for (map<string, node>::iterator it = mmap.begin(); it != mmap.end(); it++) {
        score = it->second.mid;
        if (score == -1)
            score = it->second.fin;
        else if (score <= it->second.fin)
            score = it->second.fin;
        else
            score = (score * 0.4 + it->second.fin * 0.6) + 0.5;
        if (score < 60)
            continue;
        v.push_back(it->second);
        v[v.size() - 1].score = score;
    }

    sort(v.begin(), v.end(), cmp);

    for (int i = 0; i < v.size(); i++)
        cout << v[i].id << " " << v[i].online << " " << v[i].mid << " " << v[i].fin << " " << v[i].score << endl;

    return 0;
}