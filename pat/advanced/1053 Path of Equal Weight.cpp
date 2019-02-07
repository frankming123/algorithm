#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> res;
vector<int> path;
vector<int> weight(100);
vector<vector<int>> tree(100, vector<int>());
int n, m, s;

bool cmp(vector<int> &a, vector<int> &b) {
    int len = min(a.size(), b.size());
    for (int i = 0; i < len; i++)
        if (a[i] > b[i])
            return true;
        else if (a[i] < b[i])
            return false;
    // if return true, the last test will appears segment error-.-
    return false;
}

void run(int now, int sum) {
    sum += weight[now];
    if (sum > s)
        return;
    path.push_back(weight[now]);
    if (tree[now].size() == 0) {
        if (sum == s) {
            res.push_back(path);
        }
        path.pop_back();
        return;
    }
    for (int i = 0; i < tree[now].size(); i++) {
        run(tree[now][i], sum);
    }
    path.pop_back();
}

int main() {
    cin >> n >> m >> s;
    for (int i = 0; i < n; i++)
        cin >> weight[i];

    for (int i = 0; i < m; i++) {
        int tmp, num;
        cin >> tmp >> num;
        while (num--) {
            int tmp1;
            cin >> tmp1;
            tree[tmp].push_back(tmp1);
        }
    }

    run(0, 0);
    sort(res.begin(), res.end(), cmp);

    for (int i = 0; i < res.size(); i++) {
        bool flag = false;
        for (int j = 0; j < res[i].size(); j++) {
            printf("%s%d", flag ? " " : "", res[i][j]);
            flag = true;
        }
        printf("\n");
    }

    return 0;
}