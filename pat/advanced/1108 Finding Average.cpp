#include <cctype>
#include <iostream>
#include <string>

using namespace std;

bool isReal(string s) {
    bool flag = false;
    bool isdot = false;
    if (s[0] == '-' || s[0] == '+')
        s = s.substr(1);
    int dot = s.length();
    for (int i = 0; i < s.length(); i++) {
        if (isdot && s[i] == '.')
            return false;
        else if (s[i] == '.') {
            isdot = true;
            dot = i;
        } else if (!isdigit(s[i]))
            return false;
    }
    if (s.length() - dot >= 4)
        return false;
    double num = stof(s);
    if (num > 1000)
        return false;
    return true;
}

int main() {
    int n;
    cin >> n;
    string s;
    double res;
    int cnt = 0;
    while (n--) {
        cin >> s;
        if (isReal(s)) {
            res += stof(s);
            cnt++;
        } else
            printf("ERROR: %s is not a legal number\n", s.c_str());
    }
    if (cnt == 0)
        printf("The average of 0 numbers is Undefined\n");
    else
        printf("The average of %d number%s is %.2f", cnt, cnt == 1 ? "" : "s", res / cnt);
    return 0;
}