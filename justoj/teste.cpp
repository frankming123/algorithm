#include <iostream>
#include <string>

using namespace std;

int calc(string &s) {
    int st = 0, res = 0;
    for (int i = 0; i < s.length(); i++) {
        char c = s[i];
        if (c == '(') {
            st++;
        } else if (c == ')' && st != 0) {
            st--;
            res++;
        }
    }
    return res;
}

int main(int argc, char const *argv[]) {
    int n;
    cin >> n;
    int res[n];
    string s;
    for (int i = 0; i < n; i++) {
        cin >> s;
        res[i] = calc(s);
    }
    int max = 0;
    for (int i = 0; i < n; i++)
        max = res[i] > max ? res[i] : max;
    cout << max << endl;
    return 0;
}
