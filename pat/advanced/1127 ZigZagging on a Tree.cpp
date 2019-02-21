#include <iostream>
#include <vector>

using namespace std;

int n;
int in[30], post[30];
vector<vector<int>> v;

void build(int l1, int r1, int l2, int r2, int level) {
    if (l1 >= r1 || l2 >= r2)
        return;
    int root = post[r2 - 1];
    // printf("l1: %d r1: %d l2: %d r2: %d root: %d\n", l1, r1, l2, r2, root);
    if (v.size() < level)
        v.push_back(vector<int>());
    v[level - 1].push_back(root);
    int pos = l1;
    while (pos < r1 && in[pos] != root)
        pos++;

    // printf("pos: %d\n", pos);

    build(l1, pos, l2, l2 + pos - l1, level + 1);
    build(pos + 1, r1, l2 + pos - l1, r2 - 1, level + 1);
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> in[i];
    for (int i = 0; i < n; i++)
        cin >> post[i];

    build(0, n, 0, n, 1);

    bool flag = true;
    for (int i = 0; i < v.size(); i++) {
        if (!flag) {
            for (int j = 0; j < v[i].size(); j++) {
                if (i != 0 || j != 0)
                    cout << " ";
                cout << v[i][j];
            }
            flag = true;
        } else {
            for (int j = v[i].size() - 1; j >= 0; j--) {
                if (i != 0 || j != 0)
                    cout << " ";
                cout << v[i][j];
            }
            flag = false;
        }
    }
    return 0;
}