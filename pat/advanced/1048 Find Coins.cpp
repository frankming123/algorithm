#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    int n, m;
    int coins[100000];
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> coins[i];

    sort(coins, coins + n);

    int l = 0, r = n - 1;
    while (l < r) {
        int mid = coins[l] + coins[r];
        if (mid < m) {
            l++;
        } else if (mid > m) {
            r--;
        } else {
            printf("%d %d\n", coins[l], coins[r]);
            return 0;
        }
    }

    printf("No Solution\n");
    return 0;
}