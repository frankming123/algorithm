#include <iostream>

using namespace std;

int n, m;

int matrix[1001][1001];
int indice[1001];

int main() {
    cin >> n >> m;
    int tmp1, tmp2;
    for (int i = 0; i < m; i++) {
        cin >> tmp1 >> tmp2;
        matrix[tmp1][tmp2] = 1;
        if (matrix[tmp2][tmp1] == 0)
            matrix[tmp2][tmp1] = -1;
    }

    int k;
    cin >> k;
    bool needblock = false;
    for (int i = 0; i < k; i++) {
        bool flag = false;
        for (int j = 0; j < n; j++)
            cin >> indice[j];
        for (int j = 1; j < n; j++) {
            if (matrix[indice[j - 1]][indice[j]] == -1) {
                flag = true;
                break;
            }
        }
        if (flag) {
            if (needblock)
                cout << " ";
            cout << i;
            needblock = true;
        }
    }
    return 0;
}