#include <iostream>
#include <vector>

using namespace std;

int degree[501];
vector<int> matrix[501];
bool visited[501];

void dfs(int now) {
    if (visited[now])
        return;
    visited[now] = true;
    for (int i = 0; i < matrix[now].size(); i++)
        dfs(matrix[now][i]);
}

int main() {
    int n, m;
    cin >> n >> m;
    int t1, t2;
    while (m--) {
        cin >> t1 >> t2;
        degree[t1]++;
        degree[t2]++;
        matrix[t1].push_back(t2);
        matrix[t2].push_back(t1);
    }
    dfs(1);
    bool flag = false;
    for (int i = 1; i <= n; i++)
        if (!visited[i])
            flag = true;
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (degree[i] % 2 == 1)
            cnt++;
        if (i != 1)
            cout << " ";
        cout << degree[i];
    }
    cout << endl;

    if (flag)
        cout << "Non-Eulerian";
    else if (cnt == 0)
        cout << "Eulerian";
    else if (cnt == 2)
        cout << "Semi-Eulerian";
    else
        cout << "Non-Eulerian";
    return 0;
}