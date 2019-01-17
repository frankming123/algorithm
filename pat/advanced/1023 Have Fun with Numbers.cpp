#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

string doubleIt(string str) {
    stringstream sstream;
    int digit, tmp, up = 0;
    for (int i = str.length() - 1; i >= 0; i--) {
        digit = (str[i] - '0') * 2 + up;
        sstream << digit % 10;
        up = digit / 10;
    }
    if (up != 0)
        sstream << up;

    string res = sstream.str();
    reverse(res.begin(), res.end());
    return res;
}

int main(int argc, char const *argv[]) {
    string str, res;
    cin >> str;
    res = doubleIt(str);
    int count[10] = {0};
    for (int i = 0; i < str.length(); i++)
        count[str[i] - '0']++;
    for (int i = 0; i < res.length(); i++)
        count[res[i] - '0']--;

    bool flag = false;
    for (int i = 0; i < 10; i++)
        if (count[i] != 0)
            flag = true;

    printf("%s\n", flag ? "No" : "Yes");
    cout << res << endl;
    return 0;
}
