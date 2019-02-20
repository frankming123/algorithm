#include <iostream>

using namespace std;

int n, m;

int edge1[10000], edge2[10000];
int query[10000];

int main() {
    cin >> n >> m;
    int t1, t2;
    for (int i = 0; i < m; i++)
        cin >> edge1[i] >> edge2[i];

    int k;
    cin >> k;
    while (k--) {
        cin >> t1;
        fill(query, query + n, 0);
        while (t1--) {
            cin >> t2;
            query[t2] = 1;
        }
        bool flag = false;
        for (int i = 0; i < m; i++)
            if (query[edge1[i]] == 0 && query[edge2[i]] == 0)
                flag = true;

        if (flag)
            cout << "No" << endl;
        else
            cout << "Yes" << endl;
    }
    return 0;
}