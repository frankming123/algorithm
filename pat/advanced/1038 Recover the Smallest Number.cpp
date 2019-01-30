#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

bool cmp(string a, string b) {
    for (int i = 0; i < a.length() || i < b.length(); i++) {
        if (i >= a.length()) {
            b = b.substr(i);
            i = -1;
        } else if (i >= b.length()) {
            a = a.substr(i);
            i = -1;
        } else if (a[i] < b[i])
            return true;
        else if (a[i] > b[i])
            return false;
    }
    return false;
}

int main() {
    string strs[10000];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> strs[i];

    sort(strs, strs + n, cmp);
    string str;
    for (int i = 0; i < n; i++)
        str += strs[i];
    while (str.length() > 1 && str[0] == '0')
        str.erase(0, 1);
    cout << str;
    return 0;
}