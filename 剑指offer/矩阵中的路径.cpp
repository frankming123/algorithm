#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int row, col;
    vector<bool> path;
    bool isRight;
    void run(char *matrix, char *str, int now) {
        if (path[now])
            return;
        if (*str == '\0' || (*(str + 1) == '\0' && *str == *(matrix + now)))
            isRight = true;
        if (isRight == true)
            return;
        if (*(matrix + now) != *str)
            return;
        path[now] = true;
        int r = now / col, c = now % col;
        if (c > 0)
            run(matrix, str + 1, now - 1);
        if (c < col - 1)
            run(matrix, str + 1, now + 1);
        if (r > 0)
            run(matrix, str + 1, now - col);
        if (r < row - 1)
            run(matrix, str + 1, now + col);
        path[now] = false;
    }
    bool hasPath(char *matrix, int rows, int cols, char *str) {
        row = rows;
        col = cols;
        isRight = false;
        path = vector<bool>(row * col, 0);
        for (int i = 0; i < rows * cols; i++)
            run(matrix, str, i);
        return isRight;
    }
};
int main() {
    Solution s;
    char matrix[] = "ABCESFCSADEE", str[] = "ABCB";
    cout << s.hasPath(matrix, 3, 4, str);
    return 0;
}