#include <iostream>
#include <set>
#include <string>

using namespace std;

int main() {
    int m, n, s;
    cin >> m >> n >> s;
    set<string> sset;
    int cnt = 0;
    string str;
    bool flag = false;
    while (m--) {
        cin >> str;
        if (sset.find(str) != sset.end())
            continue;
        cnt++;
        if (cnt == s || (cnt > s && (cnt - s) % n == 0)) {
            cout << str << endl;
            sset.insert(str);
            flag = true;
        }
    }
    if (!flag)
        cout << "Keep going..." << endl;
    return 0;
}