#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n, m, k;

int cap[100];

struct stu {

    int id, ge, gi;
    int choice[5] = {-1, -1, -1, -1, -1};
} stus[40000];

bool cmp(stu &a, stu &b) {
    if (a.ge + a.gi == b.ge + b.gi)
        return a.ge > b.ge;
    return a.ge + a.gi > b.ge + b.gi;
}
bool cmp1(stu &a, stu &b) {
    return a.id < b.id;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin >> n >> m >> k;
    vector<vector<stu>> res(m, vector<stu>());
    for (int i = 0; i < m; i++)
        cin >> cap[i];
    for (int i = 0; i < n; i++) {
        cin >> stus[i].ge >> stus[i].gi;
        stus[i].id = i;
        for (int j = 0; j < k; j++)
            cin >> stus[i].choice[j];
    }
    sort(stus, stus + n, cmp);

    for (int i = 0; i < n; i++) {
        //printf("stu%d: %d %d\n", stus[i].id, stus[i].ge, stus[i].gi);
        for (int j = 0; j < k; j++) {
            int sch = stus[i].choice[j];
            if (sch != -1) {
                if (cap[sch] > 0) {
                    cap[sch]--;
                    res[sch].push_back(stus[i]);
                    break;
                } else if (cap[sch] == 0 && (res[sch][res[sch].size() - 1].ge == stus[i].ge && res[sch][res[sch].size() - 1].gi == stus[i].gi)) {
                    res[sch].push_back(stus[i]);
                    break;
                }
            }
        }
    }

    for (int i = 0; i < res.size(); i++) {
        sort(res[i].begin(), res[i].end(), cmp1);
        for (int j = 0; j < res[i].size(); j++) {
            if (j != 0)
                cout << " ";
            cout << res[i][j].id;
        }
        cout << endl;
    }
    return 0;
}