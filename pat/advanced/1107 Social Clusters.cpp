#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

int n;
int pre[1001];
int find(int now) {
    int root = now;
    while (root != pre[root])
        root = pre[root];
    while (now != root) {
        int tmp = now;
        now = pre[now];
        pre[tmp] = root;
    }
    return root;
}
void myunion(int a, int b) {
    int root1 = find(a), root2 = find(b);
    pre[root1] = root2;
}
bool cmp(int a, int b) {
    return a > b;
}
int human[1001];

int main() {
    for (int i = 0; i < 1001; i++)
        pre[i] = i;
    scanf("%d", &n);

    int t1, t2, t3;
    for (int i = 0; i < n; i++) {
        scanf("%d:%d", &t1, &t2);
        human[i] = t2;
        for (int i = 1; i < t1; i++) {
            scanf("%d", &t3);
            myunion(t2, t3);
        }
    }

    map<int, int> mmap;
    for (int i = 0; i < n; i++) {
        int root = find(human[i]);
        // printf("root: %d\n", root);
        if (mmap.find(root) == mmap.end())
            mmap[root] = 1;
        else
            mmap[root]++;
    }
    vector<int> res;
    for (map<int, int>::iterator it = mmap.begin(); it != mmap.end(); it++)
        res.push_back(it->second);
    sort(res.begin(), res.end(), cmp);

    printf("%d\n", res.size());
    for (int i = 0; i < res.size(); i++) {
        if (i != 0)
            printf(" ");
        printf("%d", res[i]);
    }
    return 0;
}