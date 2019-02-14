#include <iostream>

using namespace std;

#define ll long long

int main() {
    int n;
    cin >> n;
    ll a, b, c;
    for (int i = 1; i <= n; i++) {
        cin >> a >> b >> c;
        ll res = a + b;
        bool flag = res > c;
        if (a > 0 && b > 0 && res <= 0)
            flag = true;
        else if (a < 0 && b < 0 && res >= 0)
            flag = false;
        printf("Case #%d: %s\n", i, flag ? "true" : "false");
    }
    return 0;
}