#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

set<char> cset;

vector<char> carray;

char capture(char c) {
    if (c >= 'a' && c <= 'z')
        return c - 'a' + 'A';
    return c;
}

void compare(string s1, string s2) {
    if (s1.length() == 0)
        return;
    else if (s2.length() == 0) {
        if (cset.count(capture(s1[0])) == 0)
            carray.push_back(capture(s1[0]));
        cset.insert(capture(s1[0]));
        compare(s1.substr(1), s2);
        return;
    }

    if (s1[0] == s2[0]) {
        compare(s1.substr(1), s2.substr(1));
        return;
    } else {
        if (cset.count(capture(s1[0])) == 0)
            carray.push_back(capture(s1[0]));
        cset.insert(capture(s1[0]));
        compare(s1.substr(1), s2);
        return;
    }
}

int main(int argc, char const *argv[]) {
    string s1, s2;
    cin >> s1 >> s2;
    compare(s1, s2);
    for (auto i : carray)
        cout << i;
    return 0;
}
