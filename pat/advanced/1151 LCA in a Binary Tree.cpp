// test2 segment fault...=.=, using map instead of array storing parent can solve it;
#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
#include <map>

using namespace std;

int m, n;
int u, v;

int in[10001], pre[10001];
// int parent[10001];
map<int,int> parent;
set<int> exists;

void buildtree(int inl, int inr, int prel, int prer) {
    if (inr - inl == 0 || prer - prel == 0)
        return;
    int root = pre[prel];
    int pos = inl;
    while (in[pos] != root)
        pos++;

    if (prer - prel > 1)
        parent[pre[prel + 1]] = pre[prel];
    if (prel + pos - inl + 1 < prer)
        parent[pre[prel + pos - inl + 1]] = pre[prel];
    buildtree(inl, pos, prel + 1, prel + pos - inl + 1);
    buildtree(pos + 1, inr, prel + pos - inl + 1, prer);
}

int main() {
    cin >> m >> n;
    for (int i = 0; i < n; i++) {
        cin >> in[i];
        exists.insert(in[i]);
    }
    for (int i = 0; i < n; i++)
        cin >> pre[i];
    buildtree(0, n, 0, n);

    int tmp1, tmp2;
    while (m--) {
        cin >> tmp1 >> tmp2;
        bool find1 = true, find2 = true;
        if (exists.find(tmp1) == exists.end())
            find1 = false;
        if (exists.find(tmp2) == exists.end())
            find2 = false;
        if (!find1 && !find2)
            printf("ERROR: %d and %d are not found.\n", tmp1, tmp2);
        else if (!find1)
            printf("ERROR: %d is not found.\n", tmp1);
        else if (!find2)
            printf("ERROR: %d is not found.\n", tmp2);
        else {
            vector<int> v1, v2;
            int node1 = tmp1, node2 = tmp2;
            while (node1 != 0) {
                v1.push_back(node1);
                node1 = parent[node1];
            }
            while (node2 != 0) {
                v2.push_back(node2);
                node2 = parent[node2];
            }
            int pos = 0;
            reverse(v1.begin(), v1.end());
            reverse(v2.begin(), v2.end());
            while (pos < v1.size() && pos < v2.size()) {
                if (v1[pos] != v2[pos])
                    break;
                pos++;
            }
            int node = v1[pos - 1];
            if (node == tmp1)
                printf("%d is an ancestor of %d.\n", tmp1, tmp2);
            else if (node == tmp2)
                printf("%d is an ancestor of %d.\n", tmp2, tmp1);
            else
                printf("LCA of %d and %d is %d.\n", tmp1, tmp2, node);
        }
    }
    return 0;
}