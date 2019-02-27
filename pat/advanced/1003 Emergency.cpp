#include <iostream>
#include <map>

using namespace std;

int n, m, c1, c2;
// 每个城市的救援人员数量
int team[500];
// map保存每个城市的相邻城市以及对应的距离
map<int, int> dis[500];
// 是否访问,防止重复访问
bool visits[500];
// 到达目的地时的最短距离,及此时的最多人员,及相同距离的路径有多少个
int mindis = 99999999, maxteam, cnt;

void dfs(int now, int discnt, int teamcnt) {
    if (now == c2) {
        if (discnt < mindis) {
            mindis = discnt;
            maxteam = teamcnt;
            cnt = 1;
        } else if (discnt == mindis) {
            cnt++;
            maxteam = teamcnt > maxteam ? teamcnt : maxteam;
        }
        return;
    }
    for (map<int, int>::iterator it = dis[now].begin(); it != dis[now].end(); it++) {
        if (visits[it->first])
            continue;
        visits[it->first] = true;
        dfs(it->first, discnt + it->second, teamcnt + team[it->first]);
        visits[it->first] = false;
    }
}

int main() {
    scanf("%d%d%d%d", &n, &m, &c1, &c2);
    for (int i = 0; i < n; i++)
        cin >> team[i];
    int t1, t2, t3;
    while (m--) {
        cin >> t1 >> t2 >> t3;
        dis[t1][t2] = t3;
        dis[t2][t1] = t3;
    }
    dfs(c1, 0, team[c1]);
    printf("%d %d", cnt, maxteam);
    return 0;
}
