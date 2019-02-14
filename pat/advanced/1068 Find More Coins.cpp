#include <algorithm>
#include <iostream>

using namespace std;

int num[10000];
int n, m;

int total;
int path[10000];
int plen, rlen;
bool flag;

void backTrack(int now) {
    if (flag || now >= n)
        return;
    if ((num[now] + total) > m)
        return;

    total += num[now];
    path[plen++] = num[now];
    if (total == m) {
        // printf("path:");
        // for (int i = 0; i < plen; i++)
        //     printf(" %d", path[i]);
        // printf("\n");
        rlen = plen;
        flag = true;
        return;
    }
    backTrack(now + 1);
    total -= num[now];
    plen--;

    backTrack(now + 1);
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> num[i];
    sort(num, num + n);
    backTrack(0);
    if (rlen == 0) {
        printf("No Solution\n");
        return 0;
    }
    for (int i = 0; i < rlen; i++) {
        if (i != 0)
            printf(" ");
        printf("%d", path[i]);
    }
    return 0;
}