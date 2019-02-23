#include <iostream>

using namespace std;

int num[10000];

bool isPrime(int n) {
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0)
            return false;
    return true;
}

int main() {
    fill(num, num + 10000, -1);
    int n, k;
    cin >> n;
    int tmp;
    for (int i = 1; i <= n; i++) {
        cin >> tmp;
        if (i == 1)
            num[tmp] = 0;
        else if (isPrime(i))
            num[tmp] = 1;
        else
            num[tmp] = 2;
    }
    cin >> k;
    while (k--) {
        cin >> tmp;
        if (num[tmp] == -2)
            printf("%04d: Checked\n", tmp);
        else if (num[tmp] == -1)
            printf("%04d: Are you kidding?\n", tmp);
        else {
            if (num[tmp] == 0)
                printf("%04d: Mystery Award\n", tmp);
            else if (num[tmp] == 1)
                printf("%04d: Minion\n", tmp);
            else if (num[tmp] == 2)
                printf("%04d: Chocolate\n", tmp);
            num[tmp] = -2;
        }
    }
    return 0;
}