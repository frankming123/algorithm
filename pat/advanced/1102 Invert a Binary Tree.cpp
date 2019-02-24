#include <iostream>
#include <queue>
#include <string>

using namespace std;

int n;
struct node {
    int l = -1, r = -1;
} tree[10];
int root;
int exists[10];
bool flagb;

void dfs(int now) {
    if (now == -1)
        return;
    dfs(tree[now].l);
    if (flagb)
        printf(" ");
    printf("%d", now);
    flagb = true;
    dfs(tree[now].r);
}

int main() {
    cin >> n;
    string s;
    for (int i = 0; i < n; i++) {
        cin >> s;
        if (s[0] != '-') {
            tree[i].r = stoi(s);
            exists[stoi(s)] = 1;
        }
        cin >> s;
        if (s[0] != '-') {
            tree[i].l = stoi(s);
            exists[stoi(s)] = 1;
        }
    }
    for (int i = 0; i < n; i++)
        if (!exists[i])
            root = i;

    queue<int> qu;
    qu.push(root);
    bool flag = false;
    while (!qu.empty()) {
        int now = qu.front();
        qu.pop();
        if (flag)
            printf(" ");
        printf("%d", now);
        flag = true;
        if (tree[now].l != -1)
            qu.push(tree[now].l);
        if (tree[now].r != -1)
            qu.push(tree[now].r);
    }
    printf("\n");
    dfs(root);
    return 0;
}