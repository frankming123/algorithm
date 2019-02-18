#include <iostream>

using namespace std;

int n, m;

int road[201][201];
int passed[201];

int main() {
    cin >> n >> m;
    int tmp1, tmp2, tmp3, dist;
    while (m--) {
        cin >> tmp1 >> tmp2 >> dist;
        road[tmp1][tmp2] = dist;
        road[tmp2][tmp1] = dist;
    }

    int k;
    cin >> k;
    int mindist = 99999999, minid = 0;
    for (int i = 1; i <= k; i++) {
        cin >> tmp1;
        cin >> tmp2;
        dist = 0;
        bool flag = true;
        fill(passed + 1, passed + n + 1, 0);
        int root = tmp2;
        bool isSimple = true;
        for (int j = 1; j < tmp1; j++) {
            cin >> tmp3;
            passed[tmp3]++;
            if (flag && road[tmp2][tmp3] == 0) {
                printf("Path %d: NA (Not a TS cycle)\n", i);
                flag = false;
            }
            if (flag) {
                dist += road[tmp2][tmp3];
                tmp2 = tmp3;
            }
        }
        if (!flag)
            continue;
        for (int j = 1; j <= n; j++) {
            if (passed[j] > 1)
                isSimple = false;
            else if (passed[j] == 0)
                flag = false;
        }
        if (!flag)
            printf("Path %d: %d (Not a TS cycle)\n", i, dist);
        else {
            if (isSimple)
                printf("Path %d: %d (TS simple cycle)\n", i, dist);
            else
                printf("Path %d: %d (TS cycle)\n", i, dist);
            if (mindist > dist) {
                mindist = dist;
                minid = i;
            }
        }
    }
    printf("Shortest Dist(%d) = %d", minid, mindist);
    return 0;
}