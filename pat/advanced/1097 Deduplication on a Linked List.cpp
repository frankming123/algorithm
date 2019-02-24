#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int root, n;
struct node {
    int addr, val, next;
} list[100000];
int exists[10001];

int main() {
    cin >> root >> n;
    int t1, t2, t3;
    while (n--) {
        cin >> t1 >> t2 >> t3;
        list[t1].addr = t1;
        list[t1].val = t2;
        list[t1].next = t3;
    }

    vector<int> v1, v2;
    while (root != -1) {
        if (exists[abs(list[root].val)])
            v2.push_back(root);
        else {
            exists[abs(list[root].val)] = 1;
            v1.push_back(root);
        }
        root = list[root].next;
    }

    if (v1.size()) {
        for (int i = 0; i < v1.size() - 1; i++)
            printf("%05d %d %05d\n", list[v1[i]].addr, list[v1[i]].val, list[v1[i + 1]].addr);
        printf("%05d %d -1\n", list[v1[v1.size() - 1]].addr, list[v1[v1.size() - 1]].val);
    }
    if (v2.size()) {
        for (int i = 0; i < v2.size() - 1; i++)
            printf("%05d %d %05d\n", list[v2[i]].addr, list[v2[i]].val, list[v2[i + 1]].addr);
        printf("%05d %d -1\n", list[v2[v2.size() - 1]].addr, list[v2[v2.size() - 1]].val);
    }

    return 0;
}