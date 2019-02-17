#include <cmath>
#include <iostream>

using namespace std;

int m, n;
int visited[10010];

bool isprime(int n) {
    if (n == 1)
        return false;
    int sqrtn = sqrt(n);
    for (int i = 2; i <= sqrtn; i++)
        if (n % i == 0)
            return false;
    return true;
}

int main() {
    cin >> m >> n;
    while (!isprime(m))
        m++;
    int num, res;
    for (int i = 0; i < n; i++) {
        cin >> num;
        if (i != 0)
            printf(" ");
        for (int j = 0; j < m; j++) {
            res = (num + j * j) % m;
            if (!visited[res]) {
                printf("%d", res);
                break;
            }
        }
        if (visited[res])
            printf("-");
        else
            visited[res] = 1;
    }

    return 0;
}