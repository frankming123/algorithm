#include <iostream>
#include <string>

using namespace std;

int calc(string &s) {
    if (s.length() == 1)
        return 1;
    int count = 1;
    for (int i = 1; i < s.length(); i++)
        if (s[i] != s[i - 1])
            count++;
    return count;
}

int main(int argc, char const *argv[]) {
    int n;
    cin >> n;
    int res[n];
    int null;
    string s;
    for (int i = 0; i < n; i++) {
        cin >> null >> s;
        res[i] = calc(s);
    }
    for (int i = 0; i < n; i++)
        cout << res[i] << endl;
    return 0;
}
