// can not pass the last testcase
#include <iostream>
#include <vector>

using namespace std;

int n;
int tree[1000];

vector<int> res;

bool isBST = true;

void build(int l, int r) {
    if (l >= r)
        return;
    int root = tree[l];
    int pos1 = l + 1;
    while (pos1 < r && tree[pos1] < root)
        pos1++;
    int pos2 = l + 1;
    while (pos2 < r && tree[pos2] >= root)
        pos2++;

    if (pos2 < pos1) {
        for (int i = pos1; i < r; i++)
            if (tree[i] < root) {
                isBST = false;
                // printf("pos1: %d %d %d\n", pos1, tree[i], root);
            }
        build(l + 1, pos1);
        build(pos1, r);
    } else if (pos2 > pos1) {
        for (int i = pos2; i < r; i++)
            if (tree[i] >= root) {
                isBST = false;
                // printf("pos2: %d %d %d\n", pos2, tree[i], root);
            }
        build(l + 1, pos2);
        build(pos2, r);
    }
    res.push_back(root);
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> tree[i];
    build(0, n);
    if (!isBST) {
        printf("NO");
        return 0;
    }
    printf("YES\n");
    for (int i = 0; i < res.size(); i++) {
        if (i != 0)
            printf(" ");
        printf("%d", res[i]);
    }
    return 0;
}