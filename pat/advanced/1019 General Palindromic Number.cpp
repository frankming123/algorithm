#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {
    int n, b;
    cin >> n >> b;
    if (n == 0) {
        printf("Yes\n0");
        return 0;
    }
    vector<int> s;
    while (n != 0) {
        s.push_back(n % b);
        n /= b;
    }

    bool flag = false;

    for (int i = 0; i < s.size() / 2; i++)
        if (s[i] != s[s.size() - 1 - i]) {
            flag = true;
            break;
        }

    printf("%s\n", flag ? "No" : "Yes");

    printf("%d", s[s.size() - 1]);
    for (int i = s.size() - 2; i >= 0; i--)
        printf(" %d", s[i]);
    return 0;
}
