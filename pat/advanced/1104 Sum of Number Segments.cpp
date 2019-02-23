#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    double tmp, sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> tmp;
        sum += tmp * i * (n - i + 1);
    }
    printf("%.2lf", sum);
    return 0;
}