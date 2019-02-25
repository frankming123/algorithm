#include <iostream>

using namespace std;

int m, n;

int main() {
    cin >> m;
    while (m--) {
        cin >> n;
        int bit = 1, tmp = n;
        while (tmp != 0) {
            tmp /= 10;
            bit *= 10;
        }
        bool flag = false;
        for (int i = 1; i < 20; i++) {
            int total = n * n * i;
            if (total % bit == n) {
                printf("%d %d\n", i, total);
                flag = true;
                break;
            }
        }
        if (!flag)
            printf("No\n");
    }
    return 0;
}