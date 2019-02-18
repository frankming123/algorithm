#include <iostream>

using namespace std;

#define len 100010

int num[len];

int main() {
    int n;
    cin >> n;
    int tmp;
    while (n--) {
        cin >> tmp;
        if (tmp > 0 && tmp < len)
            num[tmp] = 1;
    }
    for (int i = 1; i < len; i++)
        if (num[i] == 0) {
            cout << i;
            return 0;
        }
    return 0;
}