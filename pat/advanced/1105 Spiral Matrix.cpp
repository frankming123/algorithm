#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> v;
int matrix[500][500];
int col, row;

bool cmp(int a, int b) {
    return a > b;
}

void dfs(int now, int i, int j, int flag) {
    if (now >= v.size())
        return;
    matrix[i][j] = v[now];
    if (flag == 0) {
        if (j < col - 1 && matrix[i][j + 1] == 0)
            dfs(now + 1, i, j + 1, flag);
        else
            dfs(now + 1, i + 1, j, 1);
    } else if (flag == 1) {
        if (i < row - 1 && matrix[i + 1][j] == 0)
            dfs(now + 1, i + 1, j, flag);
        else
            dfs(now + 1, i, j - 1, 2);
    } else if (flag == 2) {
        if (j > 0 && matrix[i][j - 1] == 0)
            dfs(now + 1, i, j - 1, flag);
        else
            dfs(now + 1, i - 1, j, 3);
    } else {
        if (i > 0 && matrix[i - 1][j] == 0)
            dfs(now + 1, i - 1, j, flag);
        else
            dfs(now + 1, i, j + 1, 0);
    }
}

int main() {
    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    col = 1;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0)
            col = i;
    row = n / col;
    sort(v.begin(), v.end(), cmp);
    dfs(0, 0, 0, 0);
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (j != 0)
                printf(" ");
            printf("%d", matrix[i][j]);
        }
        printf("\n");
    }
    return 0;
}