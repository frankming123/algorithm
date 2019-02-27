#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n, k;

struct node {
    int tim, use;
};
bool cmp(node &a, node &b) {
    return a.tim < b.tim;
}
vector<node> v;

int main() {
    scanf("%d%d", &n, &k);
    int t1, t2, t3, t4;
    for (int i = 0; i < n; i++) {
        scanf("%d:%d:%d%d", &t1, &t2, &t3, &t4);

        if (t1 * 3600 + t2 * 60 + t3 > 61200)
            continue;
        v.push_back(node{t1 * 3600 + t2 * 60 + t3, (t4 > 60 ? 60 : t4) * 60});
    }
    sort(v.begin(), v.end(), cmp);

    vector<int> window(k, 28800);
    int cnt = 0;
    for (int i = 0; i < v.size(); i++) {
        node now = v[i];
        int tim = window[0], winn = 0;
        for (int j = 0; j < k; j++)
            if (window[j] < tim) {
                tim = window[j];
                winn = j;
            }

        if (now.tim < tim) {
            cnt += tim - now.tim;
            window[winn] += now.use;
        } else {
            window[winn] = now.tim + now.use;
        }
    }
    printf("%.1lf", double(cnt) / 60 / v.size());
    return 0;
}