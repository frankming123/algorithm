// can not pass testpoint 8 and 9 T_T
#include <iostream>
#include <vector>

using namespace std;

int maxcost = 99999999;
int maxtake = 99999999;
int maxbring = 99999999;
vector<int> st, res;

void dfs(vector<vector<int>> &road, vector<int> &cap, vector<int> &ispassed,
         int now, int goal, int cost, int take, int bring) {
    //printf("now: %d cost: %d take: %d bring: %d\n", now, cost, take, bring);
    // printf("st: ");
    // for (int i = 0; i < st.size(); i++)
    //     printf("%d ", st[i]);
    // printf("cost: %d take: %d", cost, take);
    // printf("\n");
    if (now == goal) {
        if (cost == maxcost) {
            if (take == maxtake) {
                // printf("%d %d\n", take, maxtake);
                if (bring < maxbring) {
                    maxbring = bring;
                    res.assign(st.begin(), st.end());
                }
            } else if (take < maxtake) {
                maxtake = take;
                maxbring = bring;
                res.assign(st.begin(), st.end());
            }
        } else if (cost < maxcost) {
            maxcost = cost;
            maxtake = take;
            maxbring = bring;
            res.assign(st.begin(), st.end());
        }
        return;
    }
    ispassed[now] = 1;
    st.push_back(now);
    for (int i = 1; i < road[now].size(); i++) {
        if (ispassed[i] || road[now][i] == 0)
            continue;

        if (cap[i] > 0) {
            dfs(road, cap, ispassed, i, goal, cost + road[now][i], take,
                bring + cap[i]);
        } else if (bring + cap[i] >= 0) {
            dfs(road, cap, ispassed, i, goal, cost + road[now][i], take,
                bring + cap[i]);
        } else {
            dfs(road, cap, ispassed, i, goal, cost + road[now][i],
                take - bring - cap[i], 0);
        }
    }
    ispassed[now] = 0;
    st.pop_back();
}

int main(int argc, char const *argv[]) {
    int c, n, s, m;
    cin >> c >> n >> s >> m;

    vector<int> cap(n + 1);
    for (int i = 1; i <= n; i++) {
        int tmp;
        cin >> tmp;
        cap[i] = tmp - c / 2;
    }

    vector<vector<int>> road(n + 1, vector<int>(n + 1, 0));

    int tmp1, tmp2, tmp3;
    for (int i = 0; i < m; i++) {
        cin >> tmp1 >> tmp2 >> tmp3;
        road[tmp1][tmp2] = tmp3;
        road[tmp2][tmp1] = tmp3;
    }

    vector<int> ispassed(n, 0);

    dfs(road, cap, ispassed, 0, s, 0, 0, 0);

    // printf("%d %d\n", maxcost, maxtake);
    printf("%d ", maxtake);

    for (int i = 0; i < res.size(); i++) {
        printf("%d->", res[i]);
    }
    printf("%d %d", s, maxbring);
    return 0;
}
