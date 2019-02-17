#include <iostream>

using namespace std;

#define min(a, b) a > b ? b : a
#define max(a, b) a > b ? a : b

int n;
int pass[1000000];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &pass[i]);

    long res_max = 0, res_min = pass[0], all = 0, res;
    long total = 0;
    for (int i = 0; i < n; i++) {
        all += pass[i];
        total += pass[i];
        if (total > res_max) {
            res_max = total;
        } else if (total < 0) {
            total = 0;
        }
    }
    total = 0;
    for (int i = 0; i < n; i++) {
        total += pass[i];
        if (total < res_min) {
            res_min = total;
        } else if (total > 0) {
            total = 0;
        }
    }
    printf("%ld", max(res_max, all - res_min));
    return 0;
}