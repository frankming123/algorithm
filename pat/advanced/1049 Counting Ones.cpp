#include <cmath>
#include <iostream>

using namespace std;

int countOne(int num) {
    int n = num;
    int digit = 0;
    int bit = 0;
    int total = 0;
    while (n != 0) {
        digit = n % 10;
        n /= 10;
        if (digit == 0) {
            total += n * pow(10, bit);
        } else if (digit == 1) {
            total += n * pow(10, bit);
            total += num % int(pow(10, bit)) + 1;
        } else {
            total += (n + 1) * pow(10, bit);
        }
        bit++;
    }
    return total;
}

int main() {
    int n;
    cin >> n;
    cout << countOne(n) << endl;
    return 0;
}