#include <cmath>
#include <iostream>
#include <string>

using namespace std;

bool stolerr;

long mystol(string num, int radix) {
    stolerr = false;
    long res = 0;
    bool isNeg = false;

    int digit = 0;
    for (int i = 0; i < num.length(); i++) {
        if (num[i] >= '0' && num[i] <= '9')
            digit = num[i] - '0';
        else
            digit = num[i] - 'a' + 10;
        if (digit >= radix) {
            stolerr = true;
            return 0;
        }
        res += pow(radix, num.length() - i - 1) * digit;
    }
    return res;
}

int main(int argc, char const *argv[]) {
    string n1, n2;
    int tag, radix;
    cin >> n1 >> n2 >> tag >> radix;
    long num1, num2;
    num1 = mystol(tag == 1 ? n1 : n2, radix);

    for (int i = 2; i <= 100; i++) {
        num2 = mystol(tag == 1 ? n2 : n1, i);
        if (stolerr)
            continue;
        if (num2 > num1) {
            printf("Impossible");
            return 0;
        } else if (num2 == num1) {
            printf("%d", i);
            return 0;
        }
    }
    printf("Impossible");
    return 0;
}
