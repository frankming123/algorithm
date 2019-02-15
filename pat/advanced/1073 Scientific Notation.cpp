#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;
    bool isNeg = false;
    if (s[0] == '-')
        isNeg = true;
        s = s.substr(1);

    string num;
    int pos = 0;
    while (s[pos] != 'E') {
        if (s[pos] != '.')
            num += s[pos];
        pos++;
    }
    int val = stoi(s.substr(pos + 1));

    //cout << "num: " << num << " val: " << val << endl;

    int dot = 1 + val;
    if (dot >= (int)num.length()) {
        for (int i = dot - num.length(); i != 0; i--)
            num += '0';
    } else if (dot > 0) {
        num.insert(dot, 1, '.');
    } else {
        for (int i = dot; i <= 0; i++)
            num.insert(0, 1, '0');
        num.insert(1, 1, '.');
    }
    if (isNeg)
        num.insert(0, 1, '-');
    cout << num;

    return 0;
}