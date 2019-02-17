#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

string common(string a, string b) {
    int len = min(a.length(), b.length());
    for (int i = 0; i < len; i++) {
        char ch1 = a[a.length() - 1 - i], ch2 = b[b.length() - 1 - i];
        if (ch1 != ch2)
            return a.substr(a.length() - i);
    }
    return a.substr(a.length() - len);
}

int main() {
    int n;
    cin >> n;
    string strs[n];
    cin.ignore(4096, '\n');
    for (int i = 0; i < n; i++)
        getline(cin, strs[i]);

    // for(int i=0;i<n;i++)cout<<strs[i]<<endl;
    string suffix = strs[0];
    for (int i = 1; i < n; i++) {
        suffix = common(strs[i], suffix);
        // cout << suffix << endl;
    }
    cout << (suffix == "" ? "nai" : suffix) << endl;
    return 0;
}