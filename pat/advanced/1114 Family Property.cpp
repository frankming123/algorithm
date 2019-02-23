#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n;

struct node {
    int id = -1, fat = -1, mon = -1;
    int k = 0;
    int chi[5];
    int m, a;
} nodes[10000];
struct nnode {
    int id, total;
    double sets, area;
};
bool cmp(nnode &a, nnode &b) {
    if (a.area == b.area)
        return a.id < b.id;
    return a.area > b.area;
}
bool visited[10000];

int total;
double sets, area;
int id;

void dfs(int now) {
    if (visited[now])
        return;
    // printf("now: %04d\n", now);
    visited[now] = true;
    if (now < id)
        id = now;
    total++;
    if (nodes[now].id == -1)
        return;
    sets += nodes[now].m;
    area += nodes[now].a;
    if (nodes[now].fat != -1)
        dfs(nodes[now].fat);
    if (nodes[now].mon != -1)
        dfs(nodes[now].mon);
    for (int i = 0; i < nodes[now].k; i++)
        dfs(nodes[now].chi[i]);
}

int main() {
    cin >> n;
    int t1, t2;
    for (int k = 0; k < n; k++) {
        cin >> t1;
        nodes[t1].id = t1;
        cin >> nodes[t1].fat >> nodes[t1].mon >> nodes[t1].k;
        for (int i = 0; i < nodes[t1].k; i++) {
            cin >> nodes[t1].chi[i];
            int chi = nodes[t1].chi[i];
            nodes[chi].id = chi;
            if (nodes[chi].fat != t1 && nodes[chi].mon != t1) {
                if (nodes[chi].fat == -1)
                    nodes[chi].fat = t1;
                else if (nodes[chi].mon == -1)
                    nodes[chi].mon = t1;
            }
        }
        cin >> nodes[t1].m >> nodes[t1].a;
        int fat = nodes[t1].fat, mon = nodes[t1].mon;
        bool flag = false;
        if (fat != -1) {
            nodes[fat].id = fat;
            for (int i = 0; i < nodes[fat].k; i++)
                if (nodes[fat].chi[i] == t1)
                    flag = true;
            if (!flag) {
                nodes[fat].chi[nodes[fat].k] = t1;
                nodes[fat].k++;
            }
        }
        if (mon != -1) {
            nodes[mon].id = mon;
            flag = false;
            for (int i = 0; i < nodes[mon].k; i++)
                if (nodes[mon].chi[i] == t1)
                    flag = true;
            if (!flag) {
                nodes[mon].chi[nodes[mon].k] = t1;
                nodes[mon].k++;
            }
        }
    }

    // for (int i = 0; i < 10000; i++) {
    //     if (nodes[i].id == -1)
    //         continue;
    //     printf("%d %d %d", nodes[i].id, nodes[i].fat, nodes[i].mon);
    //     for (int j = 0; j < nodes[i].k; j++)
    //         printf(" %d", nodes[i].chi[j]);
    //     printf(" %d %d\n", nodes[i].m, nodes[i].a);
    // }
    vector<nnode> res;
    for (int i = 0; i < 10000; i++) {
        if (nodes[i].id == -1 || visited[i])
            continue;
        // printf("i: %04d\n", i);
        total = 0;
        sets = area = 0.0;
        id = 10000;
        dfs(i);
        res.push_back(nnode{id, total, sets / total, area / total});
    }
    sort(res.begin(), res.end(), cmp);
    printf("%d\n", res.size());
    for (int i = 0; i < res.size(); i++)
        printf("%04d %d %.3lf %.3lf\n", res[i].id, res[i].total, res[i].sets, res[i].area);
    return 0;
}