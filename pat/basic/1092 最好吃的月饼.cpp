#include <iostream>

using namespace std;

int cnt[1001];
int n, m;

int main() {
    cin >> n >> m;
    int tmp;
    for (int i = 0; i < m; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> tmp;
            cnt[j] += tmp;
        }
    }
    int maxn = 0;
    for (int i = 1; i <= n; i++)
        if (maxn < cnt[i])
            maxn = cnt[i];
    int i = 1;
    while (cnt[i] != maxn)
        i++;
    printf("%d\n%d", maxn, i);

    while (i < n) {
        i++;
        if (cnt[i] == maxn)
            printf(" %d", i);
    }
    return 0;
}