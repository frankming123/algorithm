// it is a little difficult... I can not solve it even when had seen the answer-.-
#include <iostream>
#include <map>
#include <vector>

using namespace std;

int n, m, k;

vector<int> near[10000];
// int lineOf[10000];
map<int, int> lineOf;
int goal;
int visited[10000];
vector<int> tmpv, rv;
int rcnt, rtra;

int calc() {
    int res = -1;
    int prev = 0;
    for (int i = 1; i < tmpv.size(); i++) {
        if (lineOf[tmpv[i] * 10000 + tmpv[i - 1]] != prev)
            res++;
        prev = lineOf[tmpv[i] * 10000 + tmpv[i - 1]];
    }
    return res;
}

void dfs(int now, int cnt) {
    if (now == goal) {
        if (cnt < rcnt) {
            rv = tmpv;
            rcnt = cnt;
            rtra = calc();
        } else if (cnt == rcnt) {
            int tra = calc();
            if (tra < rtra) {
                rv = tmpv;
                rtra = tra;
            }
        }
        return;
    }
    for (int i = 0; i < near[now].size(); i++) {
        if (visited[near[now][i]])
            continue;
        visited[near[now][i]] = 1;
        tmpv.push_back(near[now][i]);
        dfs(near[now][i], cnt + 1);
        tmpv.pop_back();
        visited[near[now][i]] = 0;
    }
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> m;
        int t1, t2;
        cin >> t1;
        for (int j = 1; j < m; j++) {
            cin >> t2;
            lineOf[t2 * 10000 + t1] = i;
            lineOf[t1 * 10000 + t2] = i;
            near[t1].push_back(t2);
            near[t2].push_back(t1);
            t1 = t2;
        }
    }
    cin >> k;
    int t1, t2;
    while (k--) {
        cin >> t1 >> t2;
        goal = t2;
        fill(visited, visited + 10000, 0);
        visited[t1] = 1;
        rcnt = 99999999;
        rtra = 99999999;
        tmpv.clear();
        rv.clear();
        dfs(t1, 0);
        printf("%d\n", rcnt);
        int prev = t1, preline = 0;
        for (int i = 1; i < rv.size(); i++) {
            if (lineOf[rv[i] * 10000 + rv[i - 1]] != preline) {
                if (preline != 0) {
                    printf("Take Line#%d from %04d to %04d.\n", preline, prev, rv[i - 1]);
                    prev = rv[i - 1];
                }
                preline = lineOf[rv[i] * 10000 + rv[i - 1]];
            }
        }
        printf("Take Line#%d from %04d to %04d.\n", preline, prev, t2);
    }
    return 0;
}