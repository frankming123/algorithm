#include <iostream>
#include <set>

using namespace std;

int n, k, q;
int query[10001], bird[10001];

void draw(int tree, int color) {
    for (int i = 1; i <= 10000; i++)
        if (bird[i] == tree)
            bird[i] = color;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> k;
        int flag = i;
        for (int j = 0; j < k; j++) {
            cin >> query[j];
            if (bird[query[j]] != 0)
                flag = bird[query[j]];
        }
        for (int j = 0; j < k; j++) {
            if (bird[query[j]] == 0)
                bird[query[j]] = flag;
            else
                draw(bird[query[j]], flag);
        }
    }

    set<int> tree;
    int cnt = 0;
    for (int i = 1; i <= 10000; i++)
        if (bird[i] != 0) {
            tree.insert(bird[i]);
            cnt++;
        }
    printf("%d %d\n", tree.size(), cnt);
    cin >> k;
    int t1, t2;
    while (k--) {
        cin >> t1 >> t2;
        if (bird[t1] == bird[t2])
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}