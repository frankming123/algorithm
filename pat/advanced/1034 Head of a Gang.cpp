#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

int n, k, len;
map<string, int> name;
int cnt[2000];
int pre[2000];
struct node {
    string id;
    int total, cnt, maxcnt;
};
bool cmp(node &a, node &b) {
    return a.id < b.id;
}

int find(int now) {
    int root = now;
    while (pre[root] != root)
        root = pre[root];
    while (now != root) {
        int tmp = now;
        now = pre[now];
        pre[tmp] = root;
    }
    return root;
}
void myUnion(int a, int b) {
    int root1 = find(a), root2 = find(b);
    pre[root2] = root1;
}

int main() {
    for (int i = 0; i < 2000; i++)
        pre[i] = i;
    cin >> n >> k;
    string s1, s2;
    int tmp;
    while (n--) {
        cin >> s1 >> s2 >> tmp;
        if (name.find(s1) == name.end())
            name[s1] = len++;
        if (name.find(s2) == name.end())
            name[s2] = len++;
        cnt[name[s1]] += tmp;
        cnt[name[s2]] += tmp;
        myUnion(name[s1], name[s2]);
    }

    map<int, node> mmap;
    for (map<string, int>::iterator it = name.begin(); it != name.end(); it++) {
        int i = it->second;
        int now = find(i);
        if (mmap.find(now) == mmap.end())
            mmap[now] = node{it->first, cnt[i], 1, cnt[i]};
        else {
            mmap[now].total += cnt[i];
            mmap[now].cnt++;
            if (cnt[i] > mmap[now].maxcnt) {
                mmap[now].maxcnt = cnt[i];
                mmap[now].id = it->first;
            }
        }
    }
    vector<node> res;
    for (map<int, node>::iterator it = mmap.begin(); it != mmap.end(); it++) {
        if (it->second.total / 2 > k && it->second.cnt > 2)
            res.push_back(it->second);
    }
    sort(res.begin(), res.end(), cmp);

    cout << res.size() << endl;
    for (int i = 0; i < res.size(); i++)
        cout << res[i].id << " " << res[i].cnt << endl;

    return 0;
}