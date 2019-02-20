#include <iostream>

using namespace std;

int tree[40];
int n, k;

#define abs(a) (a < 0 ? -a : a)

bool flag;

int total = -1;
void buildTree(int l, int r, int cnt) {
    if (flag)
        return;
    if (l >= r) {
        if (total == -1)
            total = cnt;
        // cout << "cnt: " << cnt << endl;
        if (total != cnt)
            flag = true;
        return;
    }
    int root = tree[l];
    if (root > 0)
        cnt++;
    // cout << "root: " << root << endl;
    int pos = l + 1;
    while (pos < r && abs(tree[pos]) < abs(root))
        pos++;

    // cout << "pos: " << pos << endl;
    if (root < 0)
        if (l + 1 < r && tree[l + 1] < 0)
            flag = true;
        else if (pos < r && tree[pos] < 0)
            flag = true;

    buildTree(l + 1, pos, cnt);
    buildTree(pos, r, cnt);
}

int main() {
    cin >> k;
    while (k--) {
        flag = false;
        total = -1;
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> tree[i];
        if (tree[0] < 0)
            cout << "No" << endl;
        else {
            buildTree(0, n, 0);
            if (flag)
                cout << "No" << endl;
            else
                cout << "Yes" << endl;
        }
    }
    return 0;
}