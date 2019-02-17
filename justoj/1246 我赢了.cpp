#include <iostream>

using namespace std;

#define win printf("I win!\n")
#define lose printf("I lose...\n")
#define draw printf("We draw!_!\n")

int t, n, k;

void run() {
    if (k == 1)
        n % 2 == 0 ? lose : win;
    else
        win;
}

int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &k);
        run();
    }
    return 0;
}