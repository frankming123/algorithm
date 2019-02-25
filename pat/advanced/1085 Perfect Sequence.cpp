#include <algorithm>
#include <iostream>

using namespace std;

#define ll long long int

ll n, p;

ll num[100000];

int main() {
    scanf("%lld%lld", &n, &p);
    for (int i = 0; i < n; i++)
        scanf("%lld", &num[i]);

    sort(num, num + n);
    int maxn = 1;
    int j = 0;
    for (int i = 0; i < n - 1; i++) {
        while (j < n) {
            ll tmp = num[i] * p;
            if (num[j] > tmp)
                break;
            j++;
        }
        if (j - i > maxn)
            maxn = j - i;
    }
    printf("%d", maxn);
    return 0;
}