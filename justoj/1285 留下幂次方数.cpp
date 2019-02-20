#include <cmath>
#include <iostream>

using namespace std;

#define ll long long int

ll res = 1;
ll n;

void run(ll a) {
    ll sum = a * a;
    while (sum <= n) {
        res += sum;
        sum *= a;
    }
}

int main() {
    cin >> n;
    for (int i = 2; i * i <= n; i++) {
        ll sq = sqrt(i);
        if (sq * sq == i)
            continue;
        run(i);
    }
    cout << res;
    return 0;
}
