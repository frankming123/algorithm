#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int sum(int n) {
        int res = 0;
        while (n != 0) {
            res += n % 10;
            n /= 10;
        }
        return res;
    }
    int cnt;
    vector<bool> path;
    void run(int row, int col, int now, int k) {
        if (path[now])
            return;
        path[now] = true;
        int r = now / col, c = now % col;
        if (sum(r) + sum(c) > k)
            return;
        // printf("r:%d c:%d %d\n", r, c, sum(r) + sum(c));
        cnt++;
        if (r > 0)
            run(row, col, now - col, k);
        if (r < row - 1)
            run(row, col, now + col, k);
        if (c > 0)
            run(row, col, now - 1, k);
        if (c < col - 1)
            run(row, col, now + 1, k);
    }
    int movingCount(int threshold, int rows, int cols) {
        cnt = 0;
        path = vector<bool>(rows * cols, false);
        run(rows, cols, 0, threshold);
        return cnt;
    }
};
int main() {
    Solution s;
    cout << s.movingCount(3, 4, 4);
    return 0;
}