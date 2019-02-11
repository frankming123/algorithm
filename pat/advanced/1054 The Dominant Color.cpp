#include <iostream>
#include <map>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
    int m, n;
    cin >> m >> n;
    int total = m * n;
    map<int, int> colors;
    int tmp;
    int color = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> tmp;
            if (colors.count(tmp)) {
                colors[tmp]++;
            } else
                colors[tmp] = 1;
            if (colors[tmp] * 2 > total)
                color = tmp;
        }
    }

    cout << color << endl;
    return 0;
}