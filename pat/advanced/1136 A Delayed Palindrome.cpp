#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

string add(string &a, string &b) {
    string res;
    int len = max(a.length(), b.length());
    int anum, bnum;
    int tmp = 0, sum = 0;
    for (int i = 0; i < len; i++) {
        bnum = 0;
        anum = 0;
        if (i < a.length())
            anum = a[a.length() - i - 1] - '0';
        if (i < b.length())
            bnum = b[b.length() - i - 1] - '0';
        sum = anum + bnum + tmp;
        tmp = sum / 10;
        sum %= 10;
        res += sum + '0';
    }
    if (tmp != 0)
        res += tmp + '0';
    reverse(res.begin(), res.end());
    while (res.size() > 0 && res[0] == '0')
        res.erase(0, 1);
    return res;
}

bool ispara(string &s) {
    for (int i = 0; i < s.length() / 2; i++)
        if (s[i] != s[s.length() - 1 - i])
            return false;
    return true;
}

int main() {
    string s;
    cin >> s;
    if (ispara(s)) {
        cout << s << " is a palindromic number." << endl;
        return 0;
    }
    int cnt = 10;
    while (cnt--) {
        string ss = s;
        reverse(ss.begin(), ss.end());
        // while (ss.size() > 0 && ss[0] == '0')
        // ss.erase(0,1);
        string res = add(s, ss);
        cout << s << " + " << ss << " = " << res << endl;
        s = res;
        if (ispara(res)) {
            cout << res << " is a palindromic number." << endl;
            return 0;
        }
    }
    cout << "Not found in 10 iterations." << endl;
    return 0;
}