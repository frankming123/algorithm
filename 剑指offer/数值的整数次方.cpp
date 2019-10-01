#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    double Power(double base, int exponent) {
        if (exponent == 0)
            return 1;
        if (exponent < 0)
            return Power(1 / base, exponent * -1);
        if (exponent % 2 == 1)
            return Power(base, exponent - 1) * base;
        else
            return Power(base * base, exponent / 2);
    }
};
int main() {
    Solution s;
    double n;
    int m;
    cin >> n >> m;
    cout << s.Power(n, m);
    return 0;
}