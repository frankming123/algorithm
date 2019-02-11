#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int d, n;
string num;

string run(string s) {
    while (s[0] == '0')
        s.erase(s.begin());
    if (s.length() > 1 && s[0] == '.') {
        d = 0;
        int i = 1;
        while (i < s.length() && s[i] == '0') {
            d--;
            i++;
        }
        if (i == s.length())
            d = 0;
    } else {
        d = -1;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '.')
                d = i;
        }
        if (d == -1)
            d = s.length();
    }
    num.clear();
    int i = 0;
    while (s[i] == '0' || s[i] == '.')
        i++;
    while (i != s.length()) {
        if (s[i] == '.') {
            i++;
            continue;
        }
        num += s[i];
        i++;
    }

    stringstream ss;
    while (num.length() < n)
        num += "0";
    if (num.length() > n)
        num = num.substr(0, n);
    ss << "0." << num << "*10^" << d;
    return ss.str();
}

int main() {
    string a, b;
    cin >> n;
    cin >> a >> b;
    string res1 = run(a);
    string res2 = run(b);
    if (res1 == res2)
        cout << "YES"
             << " " << res1 << endl;
    else
        cout << "NO"
             << " " << res1 << " " << res2 << endl;
    return 0;
}