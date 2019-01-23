#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[]) {
    string str;
    getline(cin, str);

    int n = 1;
    while (n <= str.length() - 2 * n + 2)
        n++;
    n--;
    int blank = str.length() - 2 * n;
    n--;
    int i = 0;
    while (i < n) {
        printf("%c%*c\n", str[i], blank + 1, str[str.length() - i - 1]);
        i++;
    }
    while (i < str.length() - n) {
        printf("%c", str[i]);
        i++;
    }
    return 0;
}
