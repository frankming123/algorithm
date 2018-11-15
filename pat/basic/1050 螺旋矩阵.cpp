/*
1050 螺旋矩阵 （25 分）
本题要求将给定的 N 个正整数按非递增的顺序，填入“螺旋矩阵”。所谓“螺旋矩阵”，是指从左上角第 1 个格子开始，按顺时针螺旋方向填充。要求矩阵的规模为 m 行 n 列，满足条件：m×n 等于 N；m≥n；且 m−n 取所有可能值中的最小值。

输入格式：
输入在第 1 行中给出一个正整数 N，第 2 行给出 N 个待填充的正整数。所有数字不超过 10
​4
​​ ，相邻数字以空格分隔。

输出格式：
输出螺旋矩阵。每行 n 个数字，共 m 行。相邻数字以 1 个空格分隔，行末不得有多余空格。

输入样例：
12
37 76 20 98 76 42 53 95 60 81 58 93
输出样例：
98 95 93
42 37 81
53 20 76
58 60 76
*/
#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

bool nmin(int a, int b) { return a > b; }

int maxYueExceptN(int n) {
    for (int i = sqrt(n); i >= 1; i--) {
        if (n % i == 0)
            return i;
    }
}

void printMatrix(int **matrix, int m, int n) {
    printf("-----------------------\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    printf("-----------------------\n");
}

void transfer(int *array, int **matrix, int m, int n, int posx, int posy) {
    if (2 * posx >= n || 2 * posy >= m)
        return;
    for (int i = posx; i < n - posx; i++) {
        matrix[posy][i] = *array;
        array++;
    }
    for (int i = 1 + posy; i < m - posy; i++) {
        matrix[i][n - 1 - posx] = *array;
        array++;
    }
    if (2 * posy != m - 1) {
        for (int i = n - 2 - posx; i >= posx; i--) {
            matrix[m - 1 - posy][i] = *array;
            array++;
        }
    }
    if (2 * posx != n - 1) {
        for (int i = m - 2 - posy; i >= 1 + posy; i--) {
            matrix[i][posx] = *array;
            array++;
        }
    }
    transfer(array, matrix, m, n, posx + 1, posy + 1);
}

int main(int argc, char const *argv[]) {
    int N;
    cin >> N;
    int array[N];
    for (int i = 0; i < N; i++)
        cin >> array[i];
    sort(array, array + N, nmin);

    int n = maxYueExceptN(N), m = N / n;

    int **matrix = new int *[m];
    for (int i = 0; i < m; i++)
        matrix[i] = new int[n];
    transfer(array, matrix, m, n, 0, 0);

    for (int i = 0; i < m; i++) {
        cout << matrix[i][0];
        for (int j = 1; j < n; j++) {
            cout << " " << matrix[i][j];
        }
        cout << endl;
    }
    return 0;
}
