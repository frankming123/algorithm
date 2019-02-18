#include <iostream>
#include <vector>

using namespace std;

int m, n;

int res[1001];
int tree[1001];
int len;
bool isMax, isMin;

void buildTree(int root) {
    if (root > n)
        return;
    if (root * 2 <= n) {
        if (tree[root] > tree[root * 2])
            isMax = true;
        else if (tree[root] < tree[root * 2])
            isMin = true;
        buildTree(root * 2);
    }
    if (root * 2 + 1 <= n) {
        if (tree[root] < tree[root * 2 + 1])
            isMin = true;
        else if (tree[root] > tree[root * 2 + 1])
            isMax = true;
        buildTree(root * 2 + 1);
    }
    res[len++] = tree[root];
}

int main() {
    std::ios::sync_with_stdio(false);
    cin >> m >> n;
    while (m--) {
        for (int i = 1; i <= n; i++)
            cin >> tree[i];
        isMax = false;
        isMin = false;
        len = 0;
        buildTree(1);
        if (isMax && isMin)
            cout << "Not Heap" << endl;
        else if (isMax)
            cout << "Max Heap" << endl;
        else if (isMin)
            cout << "Min Heap" << endl;
        for (int i = 0; i < len; i++) {
            if (i != 0)
                cout << " ";
            cout << res[i];
        }
        cout << endl;
    }
    return 0;
}