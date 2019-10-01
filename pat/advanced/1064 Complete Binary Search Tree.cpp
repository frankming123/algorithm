#include <algorithm>
#include <iostream>

using namespace std;

int n;
int tree[1001], num[1001];
int len = 1;

void build(int now) {
    if (now > n)
        return;
    build(now * 2);
    tree[now] = num[len++];
    build(now * 2 + 1);
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &num[i]);
    sort(num + 1, num + n + 1);
    build(1);
    for (int i = 1; i <= n; i++) {
        if (i != 1)
            printf(" ");
        printf("%d", tree[i]);
    }
    return 0;
}