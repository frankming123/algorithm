#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define inf 99999999

int cmax, n, sp, m;
int road[510][510];
int bike[510];
vector<int> pre[510];
vector<int> tmpath, path;
int mintake = inf, minbring = inf;

void dfs(int now) {
    tmpath.push_back(now);
    if (now == 0) {
        int take = 0, bring = 0;
        for (int i = tmpath.size() - 1; i >= 0; i--) {
            int n = tmpath[i];
            if (bike[n] >= 0)
                bring += bike[n];
            else if (bring >= (0 - bike[n]))
                bring += bike[n];
            else {
                take -= bike[n] + bring;
                bring = 0;
            }
        }
        // printf("take: %d bring: %d\n", take, bring);
        if (mintake > take) {
            mintake = take;
            minbring = bring;
            path = tmpath;
        } else if (mintake == take && minbring > bring) {
            minbring = bring;
            path = tmpath;
        }
        tmpath.pop_back();
        return;
    }
    for (int i = 0; i < pre[now].size(); i++)
        dfs(pre[now][i]);
    tmpath.pop_back();
}

int main() {
    fill(road[0], road[0] + 510 * 510, inf);
    cin >> cmax >> n >> sp >> m;
    for (int i = 1; i <= n; i++) {
        cin >> bike[i];
        bike[i] -= cmax / 2;
    }
    int t1, t2, t3;
    for (int i = 0; i < m; i++) {
        cin >> t1 >> t2 >> t3;
        road[t1][t2] = t3;
        road[t2][t1] = t3;
    }

    vector<int> dis(n + 1, inf), visits(n + 1, 0);
    dis[0] = 0;
    for (int i = 0; i <= n; i++) {
        int minn = inf, pos = -1;
        for (int j = 0; j <= n; j++)
            if (visits[j] == 0 && dis[j] < minn) {
                minn = dis[j];
                pos = j;
            }
        if (pos == -1)
            break;
        visits[pos] = 1;
        for (int j = 0; j <= n; j++) {
            if (road[pos][j] == inf || visits[j])
                continue;
            if (road[pos][j] + dis[pos] < dis[j]) {
                dis[j] = dis[pos] + road[pos][j];
                pre[j].clear();
                pre[j].push_back(pos);
            } else if (road[pos][j] + dis[pos] == dis[j])
                pre[j].push_back(pos);
        }
    }
    dfs(sp);

    printf("%d 0", mintake);
    for (int i = path.size() - 2; i >= 0; i--)
        printf("->%d", path[i]);
    printf(" %d", minbring);
    return 0;
}