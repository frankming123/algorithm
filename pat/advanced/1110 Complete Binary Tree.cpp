#include <iostream>
#include <queue>
#include <string>

using namespace std;

struct node {
    int l = -1, r = -1;
} tree[20];
int n;
int exists[20];
int root;

int main() {
    cin >> n;
    string t1, t2;
    for (int i = 0; i < n; i++) {
        cin >> t1 >> t2;
        if (t1[0] != '-') {
            tree[i].l = stoi(t1);
            exists[stoi(t1)] = 1;
        }
        if (t2[0] != '-') {
            tree[i].r = stoi(t2);
            exists[stoi(t2)] = 1;
        }
    }
    for (int i = 0; i < n; i++)
        if (!exists[i]) {
            root = i;
            break;
        }

    queue<int> qu;
    qu.push(root);
    bool flag = false, iscomplete = false;
    int last = 0;

    while (!qu.empty()) {
        int now = qu.front();
        last = now;
        qu.pop();
        if (tree[now].l == -1) {
            flag = true;
        } else {
            qu.push(tree[now].l);
            if (flag)
                iscomplete = true;
        }
        if (tree[now].r == -1) {
            flag = true;
        } else {
            qu.push(tree[now].r);
            if (flag)
                iscomplete = true;
        }
    }
    printf("%s %d", iscomplete ? "NO" : "YES", iscomplete ? root : last);
    return 0;
}