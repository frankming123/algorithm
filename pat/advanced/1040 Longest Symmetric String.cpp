#include <iostream>
#include <string>

using namespace std;

int maxn = 1;
string s;

void run(int left, int right) {
    if (s[left] != s[right])
        return;
    while (left >= 1 && right < s.length() - 1)
        if (s[left - 1] == s[right + 1]) {
            left--;
            right++;
        } else
            break;

    if (maxn < right - left + 1) {
        maxn = right - left + 1;
        //cout << left << " " << right << endl;
    }
}

int main() {
    getline(cin, s);

    for (int i = 1; i < s.length() - 1; i++) {
        run(i, i);
        run(i, i + 1);
    }
    cout << maxn;
    return 0;
}