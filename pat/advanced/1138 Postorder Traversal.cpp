#include <iostream>

using namespace std;

int n;
int pre[50000], in[50000];
bool flag = false;

void buildTree(int l1, int r1, int l2, int r2) {
    if (flag || l1 >= r1 || l2 >= r2)
        return;
    int root = pre[l1];
    int pos = l2;
    for (int i = l2; i < r2; i++)
        if (in[i] == root) {
            pos = i;
            break;
        }

    buildTree(l1 + 1, l1 + 1 + pos - l2, l2, pos);
    buildTree(l1 + 1 + pos - l2, r1, pos + 1, r2);
    if (!flag) {
        cout << root << endl;
        flag = true;
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> pre[i];
    for (int i = 0; i < n; i++)
        cin >> in[i];

    buildTree(0, n, 0, n);
    return 0;
}