#include <iostream>
#include <queue>

using namespace std;

int m, n, l, t;

bool matrix[80][1300][130];
bool visits[80][1300][130];
int cnt, res;

struct node {
    int x, y, z;
};

bool isRight(int x, int y, int z) {
    if (x < 0 || x >= l || y < 0 || y >= m || z < 0 || z >= n || visits[x][y][z] || !matrix[x][y][z])
        return false;
    visits[x][y][z] = 1;
    return true;
}

void dfs(int x, int y, int z) {
    queue<node> qu;
    qu.push(node{x, y, z});
    visits[x][y][z] = 1;
    while (!qu.empty()) {
        node now = qu.front();
        x = now.x;
        y = now.y;
        z = now.z;
        qu.pop();
        cnt++;
        if (isRight(x - 1, y, z))
            qu.push(node{x - 1, y, z});
        if (isRight(x + 1, y, z))
            qu.push(node{x + 1, y, z});
        if (isRight(x, y - 1, z))
            qu.push(node{x, y - 1, z});
        if (isRight(x, y + 1, z))
            qu.push(node{x, y + 1, z});
        if (isRight(x, y, z - 1))
            qu.push(node{x, y, z - 1});
        if (isRight(x, y, z + 1))
            qu.push(node{x, y, z + 1});
    }
}
int main() {
    scanf("%d%d%d%d", &m, &n, &l, &t);
    for (int x = 0; x < l; x++)
        for (int y = 0; y < m; y++)
            for (int z = 0; z < n; z++)
                scanf("%d", &matrix[x][y][z]);

    for (int x = 0; x < l; x++)
        for (int y = 0; y < m; y++)
            for (int z = 0; z < n; z++)
                if (!visits[x][y][z] && matrix[x][y][z]) {
                    cnt = 0;
                    dfs(x, y, z);
                    if (cnt >= t)
                        res += cnt;
                }
    printf("%d", res);
    return 0;
}