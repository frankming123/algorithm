#include <iostream>
#include <set>

using namespace std;

int m, n;

int tree[10001];

int u, v;
set<int> appears;

int main() {
    scanf("%d%d", &m, &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &tree[i]);
        appears.insert(tree[i]);
        // posOfuv[tree[i]] = i;
    }
    while (m--) {
        scanf("%d%d", &u, &v);
        if (appears.find(u) == appears.end() && appears.find(v) == appears.end()) {
            printf("ERROR: %d and %d are not found.\n", u, v);
        } else if (appears.find(u) == appears.end()) {
            printf("ERROR: %d is not found.\n", u);
        } else if (appears.find(v) == appears.end()) {
            printf("ERROR: %d is not found.\n", v);
        } else {
            int res = 0;
            for (int i = 0; i < n; i++) {
                res = tree[i];
                if ((res >= u && res <= v) || (res <= u && res >= v))
                    break;
            }
            if (res == u)
                printf("%d is an ancestor of %d.\n", u, v);
            else if (res == v)
                printf("%d is an ancestor of %d.\n", v, u);
            else
                printf("LCA of %d and %d is %d.\n", u, v, res);
        }
    }
    return 0;
}