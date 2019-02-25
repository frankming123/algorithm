#include <cmath>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

#define ll long long int

ll res1, res2;
ll a1, b1, a2, b2;

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
string print(ll a, ll b) {
    if (b == 0)
        return "Inf";
    if (a == 0)
        return "0";
    bool isNeg = (a > 0 && b < 0 || (a < 0 && b > 0)) ? true : false;
    a = abs(a);
    b = abs(b);
    ll gcdn = gcd(a, b);
    a /= gcdn;
    b /= gcdn;
    ll res = a / b;
    a = a - res * b;
    stringstream ss;
    if (res != 0 && a != 0)
        ss << res << ' ' << a << '/' << b;
    else if (res != 0)
        ss << res;
    else if (a != 0)
        ss << a << '/' << b;
    else
        ss << 0;
    string s = ss.str();
    if (isNeg)
        s.insert(0, 1, '-');
    if (s[0] == '-')
        return '(' + s + ')';
    else
        return s;
}
void add() {
    res1 = a1 * b2 + b1 * a2;
    res2 = a2 * b2;
}
void reduce() {
    res1 = a1 * b2 - b1 * a2;
    res2 = a2 * b2;
}
void multi() {
    res1 = a1 * b1;
    res2 = a2 * b2;
}
void div() {
    res1 = a1 * b2;
    res2 = a2 * b1;
}

int main() {
    scanf("%lld/%lld %lld/%lld", &a1, &a2, &b1, &b2);
    string a = print(a1, a2), b = print(b1, b2);
    add();
    cout << a << " + " << b << " = " << print(res1, res2) << endl;
    reduce();
    cout << a << " - " << b << " = " << print(res1, res2) << endl;
    multi();
    cout << a << " * " << b << " = " << print(res1, res2) << endl;
    div();
    cout << a << " / " << b << " = " << print(res1, res2) << endl;
    return 0;
}