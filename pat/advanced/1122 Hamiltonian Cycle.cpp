#include <iostream>
#include <vector>

using namespace std;

int n, m, k;

int matrix[201][201];

int main() {
    cin >> n >> m;
    int t1, t2;
    while (m--) {
        cin >> t1 >> t2;
        matrix[t1][t2] = matrix[t2][t1] = 1;
    }
    cin >> k;
    while (k--) {
        cin >> t1;
        vector<int> query(t1);
        for (int i = 0; i < t1; i++)
            cin >> query[i];

        if (query[0] != query[query.size() - 1])
            printf("NO\n");
        else {
            bool flag = false;
            vector<int> visit(n + 1, 0);
            int pre = query[0];
            for (int i = 1; i < t1; i++) {
                visit[query[i]]++;
                // printf("pre: %d now: %d %d\n", pre, query[i], matrix[pre][query[i]]);
                if (matrix[pre][query[i]] == 0)
                    flag = true;
                pre = query[i];
            }
            for (int i = 1; i <= n; i++)
                if (visit[i] != 1)
                    flag = true;
            if (!flag)
                printf("YES\n");
            else
                printf("NO\n");
        }
    }
    return 0;
}