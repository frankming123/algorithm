#include <iostream>

using namespace std;

int calc(int n, int k) {
    if (n <= k)
        return n;
    return n + (n % k == 0 ? n / k - 1 : n / k);
}

int main(int argc, char const *argv[]) {
    int t, n, k;
    cin >> t;

    int res[t];
    for (int i = 0; i < t; i++) {
        cin >> n >> k;
        res[i] = calc(n, k);
    }

    for (int i = 0; i < t; i++)
        cout << res[i] << endl;

    return 0;
}
