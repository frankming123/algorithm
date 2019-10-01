#include <iostream>
#include <unordered_map>

using namespace std;

int t, n;
unordered_map<int, int> pre;

int find(int a) {
    int root = a;
    while (pre[root] != root)
        root = pre[root];
    while (a != root) {
        int tmp = a;
        a = pre[a];
        pre[tmp] = root;
    }
    return root;
}
void unionIt(int a, int b) {
    int r1 = find(a), r2 = find(b);
    pre[r1] = r2;
}

int main() {
    scanf("%d", &t);
    int t1, t2, t3;
    while (t--) {
        scanf("%d", &n);
        bool flag = false;
        pre.clear();
        while (n--) {
            scanf("%d%d%d", &t1, &t2, &t3);
            if (flag)
                continue;
            if (pre.find(t1) != pre.end() && pre.find(t2) != pre.end()) {
                if (t3 == 1 && find(t1) != find(t2))
                    flag = true;
                if (t3 == 0 && find(t1) == find(t2))
                    flag = true;
            } else {
                if (pre.find(t1) == pre.end())
                    pre[t1] = t1;
                if (pre.find(t2) == pre.end())
                    pre[t2] = t2;
                if (t3)
                    unionIt(t1, t2);
            }
        }
        printf("%s\n", flag ? "NO" : "YES");
    }
    return 0;
}