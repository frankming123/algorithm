#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int cnt[10];

int main() {
    string s;
    cin >> s;
    for (int i = 0; i < s.length(); i++)
        cnt[s[i] - '0']++;
    int add = 0, sum = 0;
    string res;
    for (int i = s.length() - 1; i >= 0; i--) {
        sum = (s[i] - '0') * 2 + add;
        add = sum / 10;
        sum %= 10;
        res += sum + '0';
        cnt[sum]--;
    }
    if (add != 0) {
        cnt[add]--;
        res += add + '0';
    }
    bool flag = false;
    for (int i = 0; i < 10; i++)
        if (cnt[i] != 0) {
            flag = true;
            break;
        }
    reverse(res.begin(), res.end());
    printf("%s\n%s", flag ? "No" : "Yes", res.c_str());
    return 0;
}