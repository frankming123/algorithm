#include <algorithm>
#include <cctype>
#include <cmath>
#include <iostream>
#include <string>

using namespace std;

#define ll long long int

string n1, n2;
int tag, radix;

ll transfer(string s, int base) {
    ll res = 0;
    reverse(s.begin(), s.end());
    for (int i = 0; i < s.length(); i++) {
        int num;
        if (isalpha(s[i]))
            num = s[i] - 'a' + 10;
        else
            num = s[i] - '0';
        if (base <= num)
            return -1;
        res += pow(base, i) * num;
    }
    return res;
}

int main() {
    cin >> n1 >> n2 >> tag >> radix;
    if (tag == 2)
        swap(n1, n2);

    ll num1 = transfer(n1, radix), num2;
    // printf("num1: %d\n", num1);

    int l = 2, r = 100;
    while (l < r) {
        int mid = (r + l) / 2;
        num2 = transfer(n2, mid);
        // printf("mid: %d num2: %d\n", mid, num2);
        if (num1 <= num2)
            r = mid;
        else
            l = mid + 1;
    }
    num2 = transfer(n2, l);
    if (num1 == num2)
        printf("%d", l);
    else
        printf("Impossible");
    return 0;
}