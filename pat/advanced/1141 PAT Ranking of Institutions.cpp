#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

struct node {
    string sch;
    double score;
    int cnt;
};

bool cmp(node &a, node &b) {
    if (a.score == b.score) {
        if (a.cnt == b.cnt)
            return a.sch < b.sch;
        return a.cnt < b.cnt;
    }
    return a.score > b.score;
}

int main() {
    std::ios::sync_with_stdio(false);
    string id, sch;
    int n, score;
    cin >> n;
    map<string, node> mmap;
    while (n--) {
        cin >> id >> score >> sch;
        for (int i = 0; i < sch.length(); i++)
            if (sch[i] >= 'A' && sch[i] <= 'Z')
                sch[i] -= 'A' - 'a';
        double tmp = score;
        if (id[0] == 'B')
            tmp /= 1.5;
        else if (id[0] == 'T')
            tmp *= 1.5;
        if (mmap.find(sch) != mmap.end()) {
            mmap[sch].score += tmp;
            mmap[sch].cnt++;
        } else {
            mmap[sch] = node{sch, tmp, 1};
        }
    }

    vector<node> v;
    for (map<string, node>::iterator it = mmap.begin(); it != mmap.end(); it++) {
        v.push_back(it->second);
        v[v.size() - 1].score = int(v[v.size() - 1].score);
    }

    sort(v.begin(), v.end(), cmp);
    cout << v.size() << endl;
    int cnt = 1;
    for (int i = 0; i < v.size(); i++) {
        if (i > 0 && v[i].score != v[i - 1].score)
            cnt = i + 1;
        cout << cnt << " " << v[i].sch << " " << int(v[i].score) << " " << v[i].cnt << endl;
    }
    return 0;
}