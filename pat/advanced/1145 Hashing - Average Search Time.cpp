#include <iostream>

using namespace std;

int msize, m, n;

bool isPrime(int n) {
    if (n == 1)
        return false;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0)
            return false;
    return true;
}

int table[10010];

int main() {
    cin >> msize >> n >> m;
    while (!isPrime(msize))
        msize++;

    int tmp;
    while (n--) {
        cin >> tmp;
        int num;
        bool flag = false;
        for (int i = 0; i < msize; i++) {
            num = (tmp + i * i) % msize;
            if (table[num] == 0) {
                table[num] = tmp;
                flag = true;
                break;
            }
        }
        if (!flag)
            printf("%d cannot be inserted.\n", tmp);
    }

    double time = 0.0;
    for (int i = 0; i < m; i++) {
        cin >> tmp;
        int num;
        for (int i = 0; i <= msize; i++) {
            num = (tmp + i * i) % msize;
            time += 1.0;
            if (table[num] == tmp)
                break;
            else if (table[num] == 0)
                break;
        }
    }
    printf("%.1lf", time / m);
    return 0;
}