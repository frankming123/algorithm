#include <algorithm>
#include <iostream>

using namespace std;

int root, n, k;

struct node {
    int addr, val, next;
};

node nodes[100000];
node res[100000];
int len;

int main() {
    scanf("%d %d %d", &root, &n, &k);
    int tmp1, tmp2, tmp3;
    while (n--) {
        scanf("%d %d %d", &tmp1, &tmp2, &tmp3);
        nodes[tmp1] = node{tmp1, tmp2, tmp3};
    }
    tmp1 = root;
    while (tmp1 != -1) {
        res[len++] = nodes[tmp1];
        tmp1 = nodes[tmp1].next;
    }
    for (int i = 0; i < len; i += k) {
        if (i + k > len)
            break;
        reverse(res + i, res + i + k);
    }

    for (int i = 0; i < len - 1; i++) {
        printf("%05d %d %05d\n", res[i].addr, res[i].val, res[i + 1].addr);
    }
    printf("%05d %d -1", res[len - 1].addr, res[len - 1].val);

    return 0;
}