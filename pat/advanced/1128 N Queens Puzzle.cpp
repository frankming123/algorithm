#include <iostream>
#include <set>

using namespace std;

int query[1001];
int k, n;
set<int> s1, s2, s3;

bool isOrNot() {
    s1.clear();
    s2.clear();
    s3.clear();
    for (int i = 1; i <= n; i++) {
        if (s1.find(query[i]) != s1.end())
            return false;
        if (s2.find(query[i] - i) != s2.end())
            return false;
        if (s3.find(query[i] + i) != s3.end())
            return false;
        s1.insert(query[i]);
        s2.insert(query[i] - i);
        s3.insert(query[i] + i);
    }
    return true;
}

int main() {
    cin >> k;
    while (k--) {
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> query[i];
        if (isOrNot())
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}