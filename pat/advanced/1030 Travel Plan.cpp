#include <iostream>
#include <map>
#include <stack>
#include <vector>

using namespace std;

struct use {
    int d = -1;
    int c;
};

int n, m, s, d;
vector<map<int, use>> path(500);
// vector<vector<use>> path(500, vector<use>(500));
vector<int> passed(500, 0);

int maxdistance = 1 << 31 - 1, maxcost = 1 << 31 - 1;
stack<int> trace, ftrace;
// vector<int> trace, ftrace;

void run(int now, int distance, int cost) {
    // printf("now:%d distance:%d cost:%d\n", now, distance, cost);
    passed[now] = 1;
    trace.push(now);
    // trace.push_back(now);
    if (now == d) {
        if (distance < maxdistance) {
            maxdistance = distance;
            maxcost = cost;
            ftrace = trace;
        } else if (distance == maxdistance && cost < maxcost) {
            maxcost = cost;
            ftrace = trace;
        }
        passed[now] = 0;
        trace.pop();
        // trace.pop_back();
        return;
    }
    for (map<int, use>::iterator it = path[now].begin(); it != path[now].end();
         it++) {
        if (passed[it->first])
            continue;
        run(it->first, distance + it->second.d, cost + it->second.c);
    }
    // for (int i = 0; i < n; i++) {
    //     if (passed[i] || path[now][i].d == -1)
    //         continue;
    //     run(i, distance + path[now][i].d, cost + path[now][i].c);
    // }
    passed[now] = 0;
    trace.pop();
    // trace.pop_back();
}

int main(int argc, char const *argv[]) {
    cin >> n >> m >> s >> d;
    int city1, city2, distance, cost;
    for (int i = 0; i < m; i++) {
        cin >> city1 >> city2 >> distance >> cost;
        path[city1][city2] = use{distance, cost};
        path[city2][city1] = use{distance, cost};
    }
    run(s, 0, 0);
    vector<int> res;
    while (!ftrace.empty()) {
        res.insert(res.begin(), ftrace.top());
        ftrace.pop();
    }

    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << maxdistance << " " << maxcost << endl;
    return 0;
}



// use dijkstra
#include <iostream>
#include <vector>

using namespace std;

#define inf 99999999

int n, m, s, d;
struct node {
    int dis, cost;
} city[500][500];
vector<int> near[500];

int main() {
    cin >> n >> m >> s >> d;
    int t1, t2, t3, t4;
    for (int i = 0; i < m; i++) {
        cin >> t1 >> t2 >> t3 >> t4;
        city[t1][t2].dis = t3;
        city[t1][t2].cost = t4;
        city[t2][t1].dis = t3;
        city[t2][t1].cost = t4;
        near[t1].push_back(t2);
        near[t2].push_back(t1);
    }

    vector<int> dis(n, inf), visits(n, 0), pre(n, 0), cost(n, inf);
    dis[s] = 0;
    cost[s] = 0;
    for (int i = 0; i < n; i++) {
        int minn = inf, now = -1;
        for (int j = 0; j < n; j++)
            if (!visits[j] && dis[j] < minn) {
                minn = dis[j];
                now = j;
            }
        if (now == -1)
            break;
        visits[now] = 1;
        for (int j = 0; j < near[now].size(); j++) {
            int neigh = near[now][j];
            if (!visits[neigh]) {
                if (dis[now] + city[now][neigh].dis < dis[neigh]) {
                    dis[neigh] = dis[now] + city[now][neigh].dis;
                    pre[neigh] = now;
                    cost[neigh] = cost[now] + city[now][neigh].cost;
                } else if (dis[now] + city[now][neigh].dis == dis[neigh] && cost[now] + city[now][neigh].cost < cost[neigh]) {
                    pre[neigh] = now;
                    cost[neigh] = cost[now] + city[now][neigh].cost;
                }
            }
        }
    }
    vector<int> path;
    int now = d;
    while (now != s) {
        path.push_back(now);
        now = pre[now];
    }
    path.push_back(s);
    for (int i = path.size() - 1; i >= 0; i--)
        printf("%d ", path[i]);
    printf("%d %d", dis[d], cost[d]);
    return 0;
}