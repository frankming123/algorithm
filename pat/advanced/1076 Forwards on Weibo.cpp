// can not use dfs, only bfs...(every follower has its own level)
#include <iostream>
#include <queue>

using namespace std;

int n, l;

bool follower[1001][1001];
bool passed[1001];

int run(int root) {
    int total = -1, now, size, level = l + 1;
    fill(passed + 1, passed + n + 1, false);
    queue<int> qu;
    qu.push(root);
    passed[root] = true;
    while (!qu.empty() && (level--)) {
        size = qu.size();
        while (size--) {
            now = qu.front();
            //printf("now: %d\n", now);
            qu.pop();
            total++;
            for (int i = 1; i <= n; i++)
                if (!passed[i] && follower[now][i]) {
                    passed[i] = true;
                    qu.push(i);
                }
        }
    }
    return total;
}

int main() {
    scanf("%d%d", &n, &l);
    int tmp1, tmp2;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &tmp1);
        while (tmp1--) {
            scanf("%d", &tmp2);
            follower[tmp2][i] = true;
        }
    }
    int k;
    scanf("%d", &k);
    while (k--) {
        tmp1 = -1;
        scanf("%d", &tmp2);
        printf("%d\n", run(tmp2));
    }
    return 0;
}