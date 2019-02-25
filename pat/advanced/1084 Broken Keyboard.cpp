#include <cctype>
#include <iostream>
#include <string>

using namespace std;

int cnt[128];
int visited[128];

int main() {
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);

    for (int i = 0; i < s2.length(); i++) {
        if (islower(s2[i]))
            s2[i] -= 'a' - 'A';
        cnt[s2[i]]++;
    }
    string res;
    for (int i = 0; i < s1.length(); i++) {
        if (islower(s1[i]))
            s1[i] -= 'a' - 'A';
        if (!cnt[s1[i]]) {
            if (!visited[s1[i]]) {
                visited[s1[i]] = 1;
                res += s1[i];
            }
        }
    }
    cout << res;
    return 0;
}