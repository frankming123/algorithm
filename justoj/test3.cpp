#include <algorithm>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
    int n, k;
    cin >> n >> k;
    int matrix[n][n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> matrix[i][j];

    int res[k];
    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        int num1 = 0, num2 = 0;
        int xymin = min(x, y);
        int posx = x - xymin, posy = y - xymin;
        while (posx != n && posy != n) {
            num1 += matrix[posx][posy];
            posx++;
            posy++;
        }

        posx = x;
        posy = y;
        while (posx >= 0 && posy < n) {
            num2 += matrix[posx][posy];
            posx--;
            posy++;
        }
        posx = x + 1;
        posy = y - 1;
        while (posx < n && posy >= 0) {
            num2 += matrix[posx][posy];
            posx++;
            posy--;
        }
        res[i] = max(num1, num2);
    }
    for (int i = 0; i < k; i++)
        cout << res[i] << endl;
    return 0;
}
