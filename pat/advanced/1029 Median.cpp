// 8/9-.-
#include <iostream>

using namespace std;

#define ll int

int n1, n2;
ll num1[200005];

int main() {
    scanf("%d", &n1);
    for (int i = 0; i < n1; i++)
        scanf("%d", &num1[i]);
    scanf("%d", &n2);
    ll num, res, pos = 0;
    int now = 0, mid = (n1 + n2 - 1) / 2;
    for (int i = 0; i < n2; i++) {
        scanf("%d", &num);
        while (pos < n1 && num1[pos] < num) {
            // printf("pos: %d now: %d\n", pos, now);
            if (now == mid) {
                printf("%d", num1[pos]);
                return 0;
            }
            pos++;
            now++;
        }
        // printf("i: %d now: %d\n", i, now);
        if (now == mid) {
            printf("%d", num);
            return 0;
        }
        now++;
    }
    while (pos < n1) {
        if (now == mid) {
            printf("%d", num);
            return 0;
        }
        now++;
        pos++;
    }
    return 0;
}