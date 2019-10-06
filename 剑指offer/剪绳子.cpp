#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int cutRope(int number) {
        int res = 1;
        if (number == 3)
            return 2;
        for (int i = 2; i <= number / 2; i++) {
            int sum = 1;
            int t1 = number / i, t2 = number % i;
            for (int j = 0; j < t2; j++)
                sum *= (t1 + 1);
            for (int j = t2; j < i; j++)
                sum *= t1;
            res = max(res, sum);
        }
        return res;
    }
};
int main() {
    Solution s;
    cout << s.cutRope(9);
    return 0;
}