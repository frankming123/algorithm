#include <iostream>
#include <string>

using namespace std;

#define mod 1000000007
#define phi 1000000006
#define ll unsigned long long int

string m;

ll mypow(ll n, ll mi) {
    if (mi == 0)
        return 1;
    return mypow(n * n % mod, mi / 2) * (mi % 2 == 0 ? 1 : n) % mod;
}

int main() {
    cin >> m >> m;
    ll tmp = 0;
    for (int i = 0; i < m.length(); i++)
        tmp = (tmp * 10 + m[i] - '0') % phi;
    tmp += phi;
    cout << mypow(2, tmp);
    return 0;
}