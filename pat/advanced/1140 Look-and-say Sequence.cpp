#include <iostream>
#include <string>

using namespace std;

int n;

string oneround(string &s) {
    int cnt = 0;
    char c = s[0];
    string res;
    for (int i = 0; i < s.length(); i++) {
        if (c != s[i]) {
            res += c;
            res += to_string(cnt);
            c = s[i];
            cnt = 0;
        }
        cnt++;
    }
    if (cnt > 0) {
        res += c;
        res += to_string(cnt);
    }
    return res;
}

int main() {
    string s;
    cin >> s >> n;
    for (int i = 1; i < n; i++)
        s = oneround(s);
    cout << s;
    return 0;
}