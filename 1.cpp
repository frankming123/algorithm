#include <cstdio>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

int t, n;
char s[110];

int main() {
    scanf("%d\n", &t);
    while (t--) {
        scanf("%d\n", &n);
        for (int i = 0; i < n; i++)
            scanf("%c", &s[i]);

        if (n < 11) {
            printf("NO\n");
            continue;
        } else {
            int tmp = n - 10;
            bool flag = false;
            for (int i = 0; i < tmp; i++) {
                if (s[i] == '8') {
                    printf("YES\n");
                    flag = true;
                    break;
                }
            }
            if (!flag)
                printf("NO\n");
        }
    }
    return 0;
}