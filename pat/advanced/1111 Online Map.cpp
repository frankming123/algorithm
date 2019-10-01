#include <iostream>
#include <vector>

using namespace std;
#define inf 99999999

int n, m;
struct node {
    int len, tim;
} matrix[500][500];
vector<int> near[500];

int main() {
    scanf("%d%d", &n, &m);
    int t1, t2, t3, t4, t5;
    while (m--) {
        scanf("%d%d%d%d%d", &t1, &t2, &t3, &t4, &t5);
        if (t3 == 0)
            near[t2].push_back(t1);
        near[t1].push_back(t2);
        matrix[t1][t2].len = t4;
        matrix[t1][t2].tim = t5;
        matrix[t2][t1].len = t4;
        matrix[t2][t1].tim = t5;
    }
    int s, d;
    scanf("%d%d", &s, &d);
    vector<int> dis(n, inf), visits(n, 0), pre(n, -1), tim(n, inf);
    dis[s] = 0;
    tim[s] = 0;
    for (int i = 0; i < n; i++) {
        int minn = inf, now = -1;
        for (int j = 0; j < n; j++) {
            if (!visits[j] && dis[j] < minn) {
                minn = dis[j];
                now = j;
            }
        }
        if (now == -1)
            break;
        visits[now] = 1;
        for (int j = 0; j < near[now].size(); j++) {
            int next = near[now][j];
            if (visits[next])
                continue;
            if (dis[now] + matrix[now][next].len < dis[next]) {
                dis[next] = dis[now] + matrix[now][next].len;
                pre[next] = now;
                tim[next] = tim[now] + matrix[now][next].tim;
            } else if (dis[now] + matrix[now][next].len == dis[next] && tim[now] + matrix[now][next].tim < tim[next]) {
                pre[next] = now;
                tim[next] = tim[now] + matrix[now][next].tim;
            }
        }
    }
    int now = d;
    vector<int> v1;
    while (now != s) {
        v1.push_back(now);
        now = pre[now];
    }
    int resdis = dis[d];
    fill(dis.begin(), dis.end(), inf);
    fill(visits.begin(), visits.end(), 0);
    fill(pre.begin(), pre.end(), -1);
    fill(tim.begin(), tim.end(), inf);
    dis[s] = 0;
    tim[s] = 0;
    for (int i = 0; i < n; i++) {
        int minn = inf, now = -1;
        for (int j = 0; j < n; j++) {
            if (!visits[j] && dis[j] < minn) {
                minn = dis[j];
                now = j;
            }
        }
        if (now == -1)
            break;
        visits[now] = 1;
        for (int j = 0; j < near[now].size(); j++) {
            int next = near[now][j];
            if (visits[next])
                continue;
            if (dis[now] + matrix[now][next].tim < dis[next]) {
                dis[next] = dis[now] + matrix[now][next].tim;
                pre[next] = now;
                tim[next] = tim[now] + 1;
            } else if (dis[now] + matrix[now][next].tim == dis[next] && tim[now] + 1 < tim[next]) {
                pre[next] = now;
                tim[next] = tim[now] + 1;
            }
        }
    }
    now = d;
    vector<int> v2;
    while (now != s) {
        v2.push_back(now);
        now = pre[now];
    }
    bool flag = false;
    if (v1.size() != v2.size())
        flag = true;
    else {
        for (int i = 0; i < v1.size(); i++)
            if (v1[i] != v2[i])
                flag = true;
    }
    if (!flag) {
        printf("Distance = %d; Time = %d: %d", resdis, dis[d], s);
        for (int i = v1.size() - 1; i >= 0; i--)
            printf(" -> %d", v1[i]);
        return 0;
    }
    printf("Distance = %d: %d", resdis, s);
    for (int i = v1.size() - 1; i >= 0; i--)
        printf(" -> %d", v1[i]);
    printf("\nTime = %d: %d", dis[d], s);
    for (int i = v2.size() - 1; i >= 0; i--)
        printf(" -> %d", v2[i]);
    return 0;
}