#include <algorithm>
#include <iostream>

using namespace std;

int n;
int num[100000];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> num[i];
    sort(num, num + n);
    int sum = 0, halfsum = 0;
    for (int i = 0; i < n; i++) {
        sum += num[i];
        if (i == n / 2 - 1)
            halfsum = sum;
    }
    printf("%d %d", n % 2, sum - 2 * halfsum);
    return 0;
}