#include <iostream>

using namespace std;

int nv, ne, m, k;

int matrix[201][201];

int only[201];
int query[201];

int main() {
    cin >> nv >> ne;
    int t1, t2;
    while (ne--) {
        cin >> t1 >> t2;
        matrix[t1][t2] = 1;
        matrix[t2][t1] = 1;
    }

    cin >> m;
    while (m--) {
        cin >> k;
        fill(only, only + 201, 0);
        for (int i = 0; i < k; i++)
            cin >> query[i];
        t1 = query[0];
        only[t1] = 1;
        for (int i = 1; i <= nv; i++)
            if (matrix[t1][i] == 1)
                only[i] = 1;
        for (int i = 0; i < k; i++) {
            t1 = query[i];
            only[t1]++;
            for (int i = 1; i <= nv; i++)
                if (matrix[t1][i] == 1)
                    only[i]++;
            for (int i = 1; i <= nv; i++)
                if (only[i] == 2)
                    only[i] = 1;
                else
                    only[i] = 0;
        }
        bool flag = false;
        for (int i = 0; i < k; i++) {
            t1 = query[i];
            if (only[t1] == 1)
                only[t1] = 0;
            else if (only[t1] == 0)
                flag = true;
        }
        if (flag)
            cout << "Not a Clique" << endl;
        else {
            for (int i = 1; i <= nv; i++)
                if (only[i] == 1)
                    flag = true;
            if (flag)
                cout << "Not Maximal" << endl;
            else
                cout << "Yes" << endl;
        }
    }

    return 0;
}