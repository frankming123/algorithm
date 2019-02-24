#include <cmath>
#include <iostream>

using namespace std;

#define ll long long int

int main() {
    ll n;
    cin >> n;
    int max = sqrt(n);
    int start = 0, len = 0;
    for (int i = 2; i <= max; i++) {
        int j = i, sum = 1;
        for (j = i; j <= max; j++) {
            sum *= j;
            if (n % sum != 0)
                break;
        }
        if (j - i > len) {
            start = i;
            len = j - i;
        }
    }
    if (start == 0) {
        printf("1\n%d", n);
        return 0;
    }

    printf("%d\n%d", len, start);
    for (int i = start + 1; i < start + len; i++)
        printf("*%d", i);
    return 0;
}