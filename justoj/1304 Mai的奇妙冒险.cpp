#include <iostream>

using namespace std;

int n, a[1000], b[1000];

int maxn = -1;

void dfs(int now, int cnt, int total) {
    // printf("now: %d cnt: %d total: %d\n", now, cnt, total);
    if (now == n - 1) {
        if (cnt > 0)
            total += a[now];
        if (total > maxn)
            maxn = total;
        return;
    }
    if (total - b[now] >= 0)
        dfs(now + 1, cnt, total - b[now]);
    if (cnt > 0 && total + a[now] - b[now] >= 0) {
        printf("now: %d cnt: %d total: %d\n", now, cnt, total);
        dfs(now + 1, cnt - 1, total + a[now] - b[now]);
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (int i = 0; i < n - 1; i++)
        scanf("%d", &b[i]);
    dfs(0, 3, 0);
    printf("%d", maxn);
    return 0;
}