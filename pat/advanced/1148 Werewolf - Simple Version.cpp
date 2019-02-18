#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

int n;

int path[101];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> path[i];
    }
    for (int i = 1; i <= n - 1; i++) {
        for (int j = i + 1; j <= n; j++) {
            int lier = 0;
            int isis = 0;
            for (int k = 1; k <= n; k++) {
                int say = path[k];
                if ((say > 0 && (say == i || say == j)) || (say < 0 && (-say != i && -say != j))) {
                    // printf("lier: %d\n", k);
                    lier++;
                    if (k == i || k == j)
                        isis++;
                }
            }
            // printf("%d %d %d %d\n", i, j, lier, isis);
            if (lier == 2 && isis == 1) {
                printf("%d %d", i, j);
                return 0;
            }
        }
    }
    printf("No Solution");
    return 0;
}