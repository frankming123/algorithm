#include <iostream>
#include <vector>

using namespace std;

struct node {
    int addr, val, next;
};

#define len 100000

node nodes[len];
vector<node> v1, v2, v3;

int main() {
    int n, k, root;
    cin >> root >> n >> k;
    int addr;
    for (int i = 0; i < n; i++) {
        cin >> addr;
        nodes[addr].addr = addr;
        cin >> nodes[addr].val >> nodes[addr].next;
    }

    while (root != -1) {
        if (nodes[root].val < 0)
            v1.push_back(nodes[root]);
        else if (nodes[root].val <= k)
            v2.push_back(nodes[root]);
        else
            v3.push_back(nodes[root]);
        root = nodes[root].next;
    }
    vector<node> v(v1.size() + v2.size() + v3.size());
    int vlen = 0;
    for (int i = 0; i < v1.size(); i++)
        v[vlen++] = v1[i];
    for (int i = 0; i < v2.size(); i++)
        v[vlen++] = v2[i];
    for (int i = 0; i < v3.size(); i++)
        v[vlen++] = v3[i];
    for (int i = 0; i < v.size(); i++)
        if (i != v.size() - 1)
            printf("%05d %d %05d\n", v[i].addr, v[i].val, v[i + 1].addr);
        else
            printf("%05d %d -1\n", v[i].addr, v[i].val);
    return 0;
}