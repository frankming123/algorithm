#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    int LastRemaining_Solution(int n, int m) {
        vector<int> v(n, 0);
        int res = n;
        int now = -1;
        while (res != 0) {
            // printf("res:%d now:%d\n", res, now);
            for (int i = 0; i < m; i++) {
                now++;
                now %= n;
                while (v[now]) {
                    now++;
                    now %= n;
                }
            }
            v[now] = 1;
            res--;
        }
        return now;
    }
};
int main() {
    Solution s;
    cout << s.LastRemaining_Solution(4, 4);
    return 0;
}