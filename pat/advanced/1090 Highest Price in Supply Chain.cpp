#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int n;
double p, r;
vector<int> path[100000];
vector<int> root;

int resl, cnt;

void dfs(int now, int level) {
    if (level > resl) {
        resl = level;
        cnt = 1;
    } else if (level == resl)
        cnt++;
    if (now == -1)
        for (int i = 0; i < root.size(); i++)
            dfs(root[i], level + 1);
    else
        for (int i = 0; i < path[now].size(); i++)
            dfs(path[now][i], level + 1);
}

int main() {
    cin >> n >> p >> r;
    r = (100 + r) / 100;
    int tmp;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        if (tmp == -1)
            root.push_back(i);
        else
            path[tmp].push_back(i);
    }
    dfs(-1, 0);
    printf("%.2lf %d", pow(r, resl - 1) * p, cnt);
    return 0;
}