#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

string add(string &a, string &b) {
    string res = "";
    int up = 0, tmp;
    for (int i = a.length() - 1, j = b.length() - 1; i >= 0 || j >= 0;
         i--, j--) {
        if (i < 0)
            tmp = b[j] - '0';
        else if (j < 0)
            tmp = a[j] - '0';
        else
            tmp = a[j] - '0' + b[j] - '0';

        tmp += up;
        res.insert(res.begin(), char(tmp % 10 + '0'));
        up = tmp / 10;
    }
    if (up != 0)
        res.insert(res.begin(), char(up + '0'));
    return res;
}

int main(int argc, char const *argv[]) {
    string s, tmp;
    int k, i;
    cin >> s >> k;

    for (i = 0; i < k; i++) {
        tmp = s;
        reverse(s.begin(), s.end());
        // cout << s << " " << tmp << endl;
        if (s == tmp)
            break;
        s = add(s, tmp);
    }

    cout << s << endl << i;
    return 0;
}
