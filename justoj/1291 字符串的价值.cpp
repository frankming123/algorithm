#include <iostream>
#include <string>

using namespace std;

int posl, posr;
string s;

void lenOfPara(int l, int r) {
    if (s[l] != s[r])
        return;
    while (l >= 1 && r < s.length() - 1 && s[l - 1] == s[r + 1]) {
        l--;
        r++;
    }
    posl = l;
    posr = r;
}

int main(int argc, char const *argv[]) {
    std::ios::sync_with_stdio(false);
    getline(cin, s);
    if (s.length() == 0) {
        cout << 0 << endl;
        return 0;
    }
    int maxlen = 0, maxl = 0, maxr = 0;
    for (int i = 0; i < s.length() - 1; i++) {
        lenOfPara(i, i);
        if (posr - posl + 1 > maxlen) {
            maxl = posl;
            maxr = posr;
            maxlen = posr - posl + 1;
        }
        lenOfPara(i, i + 1);
        if (posr - posl + 1 > maxlen) {
            maxl = posl;
            maxr = posr;
            maxlen = posr - posl + 1;
        }
    }
    int count = 0;
    for (int i = maxl; i <= maxr; i++) {
        if (s[i] != ' ') {
            count++;
            while (i <= maxr && s[i] != ' ')
                i++;
        }
    }
    // cout << maxlen << " " << count << " " << (maxlen - count) << endl;
    cout << (maxlen - count) << endl;

    return 0;
}
