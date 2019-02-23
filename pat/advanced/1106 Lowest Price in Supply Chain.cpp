#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int n;
double p, r;
vector<int> mem[100000];

int minlevel = 99999999, cnt = 0;

void dfs(int now, int level) {
    if (mem[now].empty()) {
        if (level < minlevel) {
            minlevel = level;
            cnt = 1;
        } else if (level == minlevel)
            cnt++;
        return;
    }
    if (level > minlevel)
        return;
    for (int i = 0; i < mem[now].size(); i++)
        dfs(mem[now][i], level + 1);
}

int main() {
    cin >> n >> p >> r;
    r = (100 + r) / 100;
    int t1, t2;
    for (int i = 0; i < n; i++) {
        cin >> t1;
        mem[i].resize(t1);
        for (int j = 0; j < t1; j++)
            cin >> mem[i][j];
    }

    dfs(0, 0);
    double res = pow(r, minlevel) * p;
    printf("%.4lf %d", res, cnt);
    return 0;
}