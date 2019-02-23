#include <iostream>
#include <string>

using namespace std;

int chars[128];

int main() {
    int n;
    string s;
    cin >> n >> s;
    for (int i = 0; i < s.length(); i++) {
        int j = i;
        while (j < s.length() && s[j] == s[i])
            j++;
        if ((j - i) % n != 0)
            chars[s[i]] = 1;
        i = j - 1;
    }
    string app;
    for (int i = 0; i < s.length(); i++) {
        if (chars[s[i]])
            continue;
        int j = i;
        while (j < s.length() && s[j] == s[i])
            j++;
        if (j - i >= n) {
            if (app.find(s[i]) == string::npos)
                app += s[i];
            s.replace(i, n, 1, s[i]);
            // printf("now: %d char: %c\n", i, s[i]);
        }
    }
    cout << app << endl
         << s;
    return 0;
}