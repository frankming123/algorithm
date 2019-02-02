#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    int m;
    cin >> m;
    vector<int> fav(m);
    for (int i = 0; i < m; i++)
        cin >> fav[i];
    int l;
    cin >> l;
    vector<int> stripe(l);
    for (int i = 0; i < l; i++)
        cin >> stripe[i];

    vector<int> path(l, 0);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < l; j++) {
            if (j == 0) {
                if (fav[i] == stripe[j])
                    path[j]++;
                continue;
            }
            path[j] = max(path[j], path[j - 1]);
            if (fav[i] == stripe[j])
                path[j]++;
        }
    }

    printf("%d\n", path[l - 1]);
    return 0;
}