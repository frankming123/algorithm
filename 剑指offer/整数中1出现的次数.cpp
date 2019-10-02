#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>

using namespace std;

class Solution {
  public:
    int NumberOf1Between1AndN_Solution(int n) {
        int cnt = 0;
        int res = 0;
        int sum = 0;
        while (n) {
            int num = n % 10;
            n /= 10;
            res += n * pow(10, cnt);
            if (num > 1) {
                res += pow(10, cnt);
            } else if (num == 1) {
                res += sum + 1;
            }
            sum += num * pow(10, cnt);
            cnt++;
        }
        return res;
    }
};
int main() {
    Solution s;
    cout << s.NumberOf1Between1AndN_Solution(10000);
    return 0;
}