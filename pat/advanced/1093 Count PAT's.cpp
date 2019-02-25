#include <iostream>
#include <string>

using namespace std;

int path[100000];

int main() {
    string s;
    getline(cin, s);

    if (s[0] == 'P')
        path[0] = 1;
    for (int i = 1; i < s.length(); i++) {
        path[i] = path[i - 1];
        if (s[i] == 'P')
            path[i]++;
    }
    path[0] = 0;
    for (int i = 1; i < s.length(); i++) {
        if (s[i] == 'A')
            path[i] += path[i - 1];
        else
            path[i] = path[i - 1];
    }
    for (int i = 1; i < s.length(); i++) {
        if (s[i] == 'T'){
            path[i] += path[i - 1];
            path[i]%=1000000007;
        }
        else
            path[i] = path[i - 1];
    }
    printf("%d\n", path[s.length() - 1]);
    return 0;
}