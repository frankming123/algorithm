#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

#define inf 99999999

int n, m;
struct node {
    int dis, tim;
} nodes[500][500];
set<int> road[500];

int goal;
bool visited[500];
int mindis1 = inf;
int mintim1 = inf;
int mintim2 = inf;
int mincnt2 = inf;
vector<int> tmppath, path1, path2;

void dfs(int now, int dis, int tim, int cnt) {
    if (now == goal) {
        if (dis < mindis1) {
            mindis1 = dis;
            mintim1 = tim;
            path1 = tmppath;
        } else if (dis == mindis1 && tim < mintim1) {
            mintim1 = tim;
            path1 = tmppath;
        }
        if (tim < mintim2) {
            mintim2 = tim;
            mincnt2 = cnt;
            path2 = tmppath;
        } else if (tim == mintim2 && cnt < mincnt2) {
            mincnt2 = cnt;
            path2 = tmppath;
        }
        return;
    }
    for (set<int>::iterator it = road[now].begin(); it != road[now].end(); it++) {
        if (visited[*it])
            continue;
        visited[*it] = true;
        tmppath.push_back(*it);
        dfs(*it, dis + nodes[now][*it].dis, tim + nodes[now][*it].tim, cnt + 1);
        visited[*it] = false;
        tmppath.pop_back();
    }
}

int main() {
    scanf("%d%d", &n, &m);
    int t1, t2, t3, t4, t5;
    while (m--) {
        scanf("%d%d%d%d%d", &t1, &t2, &t3, &t4, &t5);
        road[t1].insert(t2);
        if (t3 == 0)
            road[t2].insert(t1);
        nodes[t1][t2].dis = t4;
        nodes[t1][t2].tim = t5;
        nodes[t2][t1].dis = t4;
        nodes[t2][t1].tim = t5;
    }
    scanf("%d%d", &t1, &t2);
    goal = t2;
    visited[t1] = true;
    dfs(t1, 0, 0, 0);
    bool flag = true;
    if (path1.size() != path2.size())
        flag = false;
    for (int i = 0; i < min(path1.size(), path2.size()); i++)
        if (path1[i] != path2[i])
            flag = false;

    if (flag) {
        printf("Distance = %d; Time = %d: %d", mindis1, mintim2, t1);
        for (int i = 0; i < path1.size(); i++)
            printf(" -> %d", path1[i]);
        return 0;
    }

    printf("Distance = %d: %d", mindis1, t1);
    for (int i = 0; i < path1.size(); i++)
        printf(" -> %d", path1[i]);
    printf("\n");
    printf("Time = %d: %d", mintim2, t1);
    for (int i = 0; i < path2.size(); i++)
        printf(" -> %d", path2[i]);
    return 0;
}