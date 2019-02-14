#include <algorithm>
#include <cstdlib>
#include <iostream>

using namespace std;

int loc[1011][1011];
int n, m, k, d;

int dist[1011];
int passed[1011];

void clear() {
    for (int i = 0; i < 1011; i++) {
        passed[i] = 0;
        dist[i] = 1 << 31 - 1;
    }
}

void run(int now, int total) {
    if (passed[now])
        return;
    if (total < dist[now])
        dist[now] = total;

    passed[now] = 1;
    for (int i = 1; i <= n; i++)
        if (loc[now][i] != 0 && now != i)
            run(i, total + loc[now][i]);
    for (int i = 1001; i <= 1000 + m; i++)
        if (loc[now][i] != 0 && now != i)
            run(i, total + loc[now][i]);
    passed[now] = 0;
}

int main() {
    cin >> n >> m >> k >> d;
    int tmp1, tmp2, tmp3;
    char ctmp[4];
    while (k--) {
        cin >> ctmp;
        if (ctmp[0] == 'G')
            tmp1 = atoi(ctmp + 1) + 1000;
        else
            tmp1 = atoi(ctmp);
        cin >> ctmp;
        if (ctmp[0] == 'G')
            tmp2 = atoi(ctmp + 1) + 1000;
        else
            tmp2 = atoi(ctmp);
        cin >> tmp3;
        loc[tmp1][tmp2] = tmp3;
        loc[tmp2][tmp1] = tmp3;
    }

    int gas = 0;
    double mindis = 0, avgdis = 99999999;
    for (int i = 1001; i <= 1000 + m; i++) {
        clear();
        run(i, 0);

        int tmp1 = 1 << 31 - 1;
        double tmp2 = 0;
        bool flag = false;
        for (int j = 1; j <= n; j++) {
            if (dist[j] > d) {
                flag = true;
                break;
            }
            tmp1 = min(tmp1, dist[j]);
            tmp2 += dist[j];
        }
        tmp2 /= n;
        if (flag)
            continue;

        // printf("G%d:", i - 1000);
        // for (int i = 1; i <= n; i++)
        //     printf(" %d", dist[i]);
        // printf("\n");

        if (tmp1 > mindis) {
            gas = i;
            mindis = tmp1;
            avgdis = tmp2;
        }
        if (tmp1 == mindis && tmp2 < avgdis) {
            gas = i;
            mindis = tmp1;
            avgdis = tmp2;
        }
    }
    if (gas == 0) {
        printf("No Solution\n");
    } else {
        printf("G%d\n%.1f %.1f\n", gas - 1000, mindis, avgdis+0.0001);
    }

    return 0;
}