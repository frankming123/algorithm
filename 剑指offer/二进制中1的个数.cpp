#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    int NumberOf1(int n) {
        int tmp = 1;
        int cnt = n < 0 ? 1 : 0;
        for (int i = 0; i < 31; i++) {
            if (n & tmp)
                cnt++;
            tmp = tmp << 1;
        }
        return cnt;
    }
};
int main() {
    Solution s;
    int n;
    cin >> n;
    cout << s.NumberOf1(n) << endl;
    return 0;
}