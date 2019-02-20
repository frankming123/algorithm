#include <iostream>
#include <string>

using namespace std;

int n;

struct node {
    string val;
    int addr, l, r;
} nodes[21];
int appear[21];

string build(int root) {
    if (root == -1)
        return "";
    else if (nodes[root].l == -1 && nodes[root].r == -1)
        return nodes[root].val;
    return "(" + build(nodes[root].l) + nodes[root].val + build(nodes[root].r) + ")";
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> nodes[i].val >> nodes[i].l >> nodes[i].r;
        nodes[i].addr = i;
        if (nodes[i].l != -1)
            appear[nodes[i].l] = 1;
        if (nodes[i].r != -1)
            appear[nodes[i].r] = 1;
    }
    if (n == 1) {
        cout << nodes[1].val << endl;
        return 0;
    }
    int root = 0;
    for (int i = 1; i <= n; i++)
        if (appear[i] == 0) {
            root = i;
            break;
        }

    string res = build(root);
    res.erase(0, 1);
    res.erase(res.length() - 1, 1);
    cout << res;
    return 0;
}