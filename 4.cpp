#include <algorithm>
#include <cstdio>
#include <iostream>

using namespace std;

int n, k;
int num[100000];

int main() {
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++)
        scanf("%d", &num[i]);

    sort(num, num + n);
    int tmp = 0;
    int now = 0;
    while (k--) {
        if (now >= n) {
            printf("0\n");
            continue;
        }
        printf("%d\n", num[now] - tmp);
        tmp = num[now];
        while (now < n && tmp == num[now])
            now++;
    }
    return 0;
}