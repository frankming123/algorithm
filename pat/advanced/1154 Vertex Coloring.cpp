#include <iostream>
#include <set>

using namespace std;

int n, m;

set<int> matrix[10000];
set<int> cannot[10000];

int color;
int main() {
    std::ios::sync_with_stdio(false);
    cin >> n >> m;
    int tmp1, tmp2;
    for (int i = 0; i < m; i++) {
        cin >> tmp1 >> tmp2;
        matrix[tmp1].insert(tmp2);
        matrix[tmp2].insert(tmp1);
    }
    int k;
    cin >> k;
    while (k--) {
        bool flag = false;
        set<int> colors;
        for (int i = 0; i < n; i++)
            cannot[i].clear();
        for (int i = 0; i < n; i++) {
            cin >> color;
            if (flag)
                continue;
            if (cannot[i].find(color) != cannot[i].end())
                flag = true;
            colors.insert(color);
            for (set<int>::iterator it = matrix[i].begin(); it != matrix[i].end(); it++) {
                cannot[*it].insert(color);
            }
        }
        if (flag)
            cout << "No" << endl;
        else
            cout << colors.size() << "-coloring" << endl;
    }
    return 0;
}