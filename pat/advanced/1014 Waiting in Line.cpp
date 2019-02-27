#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n, m, k, q;

struct node {
    int id, cost;
};

int cnt[1010];

int main() {
    cin >> n >> m >> k >> q;

    vector<queue<node>> qu(n);
    queue<node> other;
    vector<int> win(n, 480);

    int tmp;
    for (int i = 1; i <= k; i++) {
        cin >> tmp;
        int pos = 0, cap = qu[0].size();
        for (int j = 0; j < n; j++)
            if (qu[j].size() < cap) {
                pos = j;
                cap = qu[j].size();
            }

        if (cap == m)
            other.push(node{i, tmp});
        else
            qu[pos].push(node{i, tmp});
    }

    while (!other.empty()) {
        int now = 0, tim = win[0] + qu[0].front().cost;
        for (int i = 0; i < n; i++) {
            if (win[i] + qu[i].front().cost < tim) {
                now = i;
                tim = win[i] + qu[i].front().cost;
            }
        }
        node cus = qu[now].front();
        qu[now].pop();
        qu[now].push(other.front());
        other.pop();
        if (win[now] >= 1020) {
            cnt[cus.id] = -1;
            continue;
        }
        win[now] += cus.cost;
        cnt[cus.id] = win[now];
    }

    for (int i = 0; i < n; i++) {
        while (!qu[i].empty()) {
            node now = qu[i].front();
            qu[i].pop();
            if (win[i] >= 1020) {
                cnt[now.id] = -1;
                continue;
            }
            win[i] += now.cost;
            cnt[now.id] = win[i];
        }
    }

    while (q--) {
        cin >> tmp;
        if (cnt[tmp] == -1)
            printf("Sorry\n");
        else
            printf("%02d:%02d\n", cnt[tmp] / 60, cnt[tmp] % 60);
    }
    return 0;
}