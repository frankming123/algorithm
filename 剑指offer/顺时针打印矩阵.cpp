#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<vector<int>> path;
    bool flag;
    vector<int> res;
    vector<int> printMatrix(vector<vector<int>> matrix) {
        flag = false;
        path.resize(matrix.size() + 2);
        for (int i = 0; i < path.size(); i++)
            path[i] = vector<int>(matrix[0].size() + 2, 0);
        path[0][1] = 1;
        path[1][path[0].size() - 1] = 1;
        path[path.size() - 2][0] = 1;
        path[path.size() - 1][path[0].size() - 2] = 1;
        // for (int i = 0; i < path.size(); i++) {
        //     for (int j = 0; j < path[i].size(); j++)
        //         printf("%d ", path[i][j]);
        //     printf("\n");
        // }
        run(matrix, 1, 1, 0);
        return res;
    }
    void run(vector<vector<int>> &matrix, int row, int col, int now) {
        if (path[row][col])
            return;
        // printf("%d %d %d\n", row, col, now);
        // printf("%s%d", flag ? " " : "", matrix[row - 1][col - 1]);
        res.push_back(matrix[row - 1][col - 1]);
        flag = true;
        path[row][col] = true;
        if (now == 0) {
            if (path[row][col + 1])
                run(matrix, row + 1, col, 1);
            else
                run(matrix, row, col + 1, 0);
        } else if (now == 1) {
            if (path[row + 1][col])
                run(matrix, row, col - 1, 2);
            else
                run(matrix, row + 1, col, 1);
        } else if (now == 2) {
            if (path[row][col - 1])
                run(matrix, row - 1, col, 3);
            else
                run(matrix, row, col - 1, 2);
        } else if (path[row - 1][col])
            run(matrix, row, col + 1, 0);
        else
            run(matrix, row - 1, col, 3);
    }
};
int main() {
    Solution s;
    // vector<vector<int>> v = vector<vector<int>>(4, vector<int>(4, 0));
    vector<vector<int>> v = vector<vector<int>>(1, vector<int>(1, 1));
    // v[0][0] = 0;
    // v[0][1] = 1;
    // v[0][2] = 2;
    // v[0][3] = 3;
    // v[3][3] = 15;
    s.printMatrix(v);
    return 0;
}