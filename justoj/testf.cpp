#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

int calc(vector<vector<char>> &matrix, int x, int y) {
    int path[x + 1][y + 1];
    for (int i = 0; i <= x; i++)
        for (int j = 0; j <= y; j++)
            path[i][j] = 0;
    path[0][0] = 1;
    for (int i = 1; i <= x; i++)
        path[i][0] = matrix[i][0] == '.' ? path[i - 1][0] : 0;
    for (int i = 1; i <= y; i++)
        path[0][i] = matrix[0][i] == '.' ? path[0][i - 1] : 0;

    for (int i = 1; i <= x; i++)
        for (int j = 1; j <= y; j++) {
            if (matrix[i][j] == '.')
                path[i][j] = path[i][j - 1] + path[i - 1][j];
            path[i][j] %= 1000000007;
        }
    return path[x][y] > 0 ? path[x][y] : -1;
}

int main(int argc, char const *argv[]) {
    int t;
    scanf("%d", &t);
    for (int a = 0; a < t; a++) {
        int n, m;
        scanf("%d%d", &n, &m);
        vector<vector<char>> matrix(n);
        for (int i = 0; i < n; i++)
            matrix[i] = vector<char>(m);
        for (int i = 0; i < n; i++) {
            getchar();
            for (int j = 0; j < m; j++) {
                matrix[i][j] = getchar();
            }
        }

        int x, y;
        scanf("%d%d", &x, &y);
        printf("%d\n", calc(matrix, x - 1, y - 1));
    }
    return 0;
}
