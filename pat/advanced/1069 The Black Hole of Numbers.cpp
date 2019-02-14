#include <algorithm>
#include <iostream>
#include <string>

bool cmp(char &a, char &b) {
    return a > b;
}

using namespace std;

int main() {
    string s;
    cin >> s;
    string s1, s2;
    int n1, n2, n3;
    while (1) {
        s1 = s;
        sort(s1.begin(), s1.end(), cmp);
        while (s1.length() < 4)
            s1 += "0";
        s2 = s;
        sort(s2.begin(), s2.end());
        while (s2.length() < 4)
            s2.insert(s2.begin(), '0');

        n1 = stoi(s1);
        n2 = stoi(s2);
        n3 = n1 - n2;
        s = to_string(n3);

        while (s.length() < 4)
            s.insert(s.begin(), '0');
        cout << s1 << " - " << s2 << " = " << s << endl;
        if (n3 == 0 || n3 == 6174)
            break;
    }
    return 0;
}