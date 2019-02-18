#include <iostream>
#include <string>

using namespace std;

int isprime(int n) {
    if (n == 0 || n == 1)
        return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0)
            return false;
    }
    return true;
}

int main() {
    int l, k;
    string s;
    cin >> l >> k >> s;
    string subs;
    for (int i = 0; i <= l - k; i++) {
        subs = s.substr(i, k);
        if (isprime(stoi(subs))) {
            cout << subs;
            return 0;
        }
    }
    cout << "404";
    return 0;
}