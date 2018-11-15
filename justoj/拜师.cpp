#include <cmath>
#include <iostream>

using namespace std;

bool isright(int n, double R, double r) {
    double pi = acos(-1);
    if (r > R)
        return false;
    else if (r == R)
        return n == 1;
    return asin(r / (R - r)) * 180 * 2 * n / pi - 0.0000001 <= 360.00000000000;
}

int main() {
    std::ios::sync_with_stdio(false);
    int t;
    cin >> t;
    bool res[t];
    for (int i = 0; i < t; i++) {
        int n;
        double R, r;
        cin >> n >> R >> r;
        res[i] = isright(n, R, r);
    }

    for (int i = 0; i < t; i++)
        cout << (res[i] ? "YES" : "NO") << endl;
    return 0;
}