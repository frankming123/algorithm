#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

struct node {
    int val, l, r;
} tree[100];
int n;
int num[100];
int len;

void dfs(int now) {
    if (now == -1)
        return;
    dfs(tree[now].l);
    tree[now].val = num[len++];
    dfs(tree[now].r);
}

int main() {
    cin >> n;
    int t1, t2;
    for (int i = 0; i < n; i++) {
        cin >> t1 >> t2;
        tree[i].l = t1;
        tree[i].r = t2;
    }
    for (int i = 0; i < n; i++)
        cin >> num[i];
    sort(num, num + n);
    dfs(0);
    queue<int> qu;
    qu.push(0);
    bool flag = false;
    while (!qu.empty()) {
        int now = qu.front();
        qu.pop();
        if (flag)
            printf(" ");
        flag = true;
        printf("%d", tree[now].val);
        if (tree[now].l != -1)
            qu.push(tree[now].l);
        if (tree[now].r != -1)
            qu.push(tree[now].r);
    }
    return 0;
}