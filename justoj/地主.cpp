#include <iostream>
#include <vector>

using namespace std;

void backTrack(vector<vector<char>> &matrix, int n, int m, int &num) {
    if (matrix[n][m] == '.')
        return;
    matrix[n][m] = '.';
    num++;
    if (n > 0)
        backTrack(matrix, n - 1, m, num);
    if (n < matrix.size() - 1)
        backTrack(matrix, n + 1, m, num);
    if (m > 0)
        backTrack(matrix, n, m - 1, num);
    if (m < matrix[0].size() - 1)
        backTrack(matrix, n, m + 1, num);
}

int main(int argc, char const *argv[]) {
    int t;
    cin >> t;
    vector<int> houses;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> matrix(n, vector<char>(m));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> matrix[i][j];
        int maxn = 0, num = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                backTrack(matrix, i, j, num);
                maxn = num > maxn ? num : maxn;
                num = 0;
            }
        houses.push_back(maxn);
    }
    for (int i = 0; i < houses.size(); i++)
        cout << houses[i] << endl;
    return 0;
}
