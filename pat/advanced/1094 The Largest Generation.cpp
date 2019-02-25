#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n, m;
vector<int> tree[101];

int main() {
    cin >> n >> m;
    int t1, t2, t3;
    while (m--) {
        cin >> t1 >> t2;
        while (t2--) {
            cin >> t3;
            tree[t1].push_back(t3);
        }
    }

    queue<int> qu;
    qu.push(1);
    int maxn = 0, maxl, level = 0;
    while (!qu.empty()) {
        level++;
        int len = qu.size();
        if (maxn < len) {
            maxn = len;
            maxl = level;
        }
        while (len--) {
            int now = qu.front();
            qu.pop();
            for (int i = 0; i < tree[now].size(); i++)
                qu.push(tree[now][i]);
        }
    }
    printf("%d %d\n", maxn, maxl);
    return 0;
}