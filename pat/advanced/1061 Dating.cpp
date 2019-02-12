#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int main() {
    string a, b, c, d;
    getline(cin, a);
    getline(cin, b);
    getline(cin, c);
    getline(cin, d);
    int len = min(a.length(), b.length());
    int i = 0;
    char week, hour, minute;
    while (i < len) {
        if (a[i] >= 'A' && a[i] <= 'G' && a[i] == b[i]) {
            week = a[i];
            i++;
            break;
        }
        i++;
    }
    while (i < len) {
        if (a[i] == b[i] && ((a[i] >= '0' && a[i] <= '9') || (a[i] >= 'A' && a[i] <= 'N'))) {
            hour = a[i];
            i++;
            break;
        }
        i++;
    }

    len = min(c.length(), d.length());
    for (i = 0; i < len; i++) {
        if (c[i] == d[i] && ((c[i] >= 'a' && c[i] <= 'z') || (c[i] >= 'A' && c[i] <= 'Z'))) {
            minute = i;
            break;
        }
    }

    char weeks[7][4] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
    if (hour >= '0' && hour <= '9')
        hour += 'A' - '0';
    else
        hour += 10;
    printf("%s %02d:%02d\n", weeks[week - 'A'], hour - 'A', minute);
    return 0;
}