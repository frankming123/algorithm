#include <cmath>
#include <iostream>

using namespace std;

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

bool calc(int num) {
    for (int i = 2; i < sqrt(num); i++)
        if (num % i == 0 && gcd(num / i, i) == 1)
            return true;
    return false;
}

int main(int argc, char const *argv[]) {
    std::ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        int num;
        cin >> num;
        cout << (calc(num) ? "YES" : "NO") << endl;
    }
    return 0;
}
