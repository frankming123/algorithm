// 7/9, but I want give up it.
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n, k, m;
struct node {
    int tim, cost, isvip;
};
vector<node> v, res;
int table[110], isvip[110];
bool cmp(node &a, node &b) {
    return a.tim < b.tim;
}
bool cmp1(node &a, node &b) {
    return a.cost < b.cost;
}

int main() {
    scanf("%d", &n);
    v.resize(n);
    int t1, t2, t3, t4, t5;
    for (int i = 0; i < n; i++) {
        scanf("%d:%d:%d%d%d", &t1, &t2, &t3, &t4, &t5);
        v[i].tim = t1 * 3600 + t2 * 60 + t3;
        v[i].cost = t4 * 60;
        v[i].isvip = t5;
    }
    scanf("%d%d", &k, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &t1);
        isvip[t1] = 1;
    }
    sort(v.begin(), v.end(), cmp);

    fill(table + 1, table + k + 1, 28800);
    vector<int> cnt(k + 1, 0);
    for (int i = 0; i < v.size(); i++) {
        int pos = 1, tim = table[1];
        for (int j = 1; j <= k; j++)
            if (table[j] < tim) {
                pos = j;
                tim = table[j];
            }
        if (tim >= 75600)
            break;
        bool flag = false;
        if (isvip[pos]) {
            for (int j = i; j < n && v[j].tim <= tim; j++)
                if (v[j].isvip) {
                    flag = true;
                    res.push_back(node{v[j].tim, tim, tim - v[j].tim});
                    table[pos] += v[j].cost;
                    v.erase(v.begin() + j);
                    cnt[pos]++;
                    i--;
                    break;
                }
        }
        if (flag)
            continue;
        if (v[i].isvip && v[i].tim >= tim) {
            int vipos = -1;
            for (int j = 1; j <= k; j++) {
                if (isvip[j] && table[j] == tim) {
                    vipos = j;
                    break;
                }
            }
            if (vipos != -1) {
                table[vipos] = v[i].tim + v[i].cost;
                res.push_back(node{v[i].tim, v[i].tim, 0});
                cnt[vipos]++;
                continue;
            }
        }
        cnt[pos]++;
        if (v[i].tim >= 75600)
            break;
        if (v[i].tim > tim) {
            res.push_back(node{v[i].tim, v[i].tim, 0});
            table[pos] = v[i].tim + v[i].cost;
        } else {
            res.push_back(node{v[i].tim, tim, tim - v[i].tim});
            table[pos] += v[i].cost;
        }
    }
    sort(res.begin(), res.end(), cmp1);
    for (int i = 0; i < res.size(); i++) {
        printf("%02d:%02d:%02d %02d:%02d:%02d %d\n", res[i].tim / 3600, res[i].tim / 60 % 60, res[i].tim % 60, res[i].cost / 3600, res[i].cost / 60 % 60, res[i].cost % 60, (res[i].isvip + 30) / 60);
    }
    for (int i = 1; i < cnt.size(); i++) {
        if (i != 1)
            printf(" ");
        printf("%d", cnt[i]);
    }
    return 0;
}