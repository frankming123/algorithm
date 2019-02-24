#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int n, k, p;

bool cmp(int a, int b) {
    return a > b;
}

vector<int> tmppath, path;
int ressum = 0;
int use[21];
int len;

void dfs(int num, int cnt, int sum, int now) {
    if (num < 0 || now < 1)
        return;
    if (cnt == 0) {
        if (num == 0) {
            if (sum > ressum) {
                ressum = sum;
                path = tmppath;
            } else if (sum == ressum) {
                bool flag = false;
                for (int i = 0; i < tmppath.size(); i++)
                    if (tmppath[i] > path[i])
                        flag = true;
                if (flag)
                    path = tmppath;
            }
        }
        return;
    }
    // printf("num: %d cnt: %d sum: %d\n", num, cnt, sum);
    for (int i = 1; i <= now && use[i] <= num; i++) {
        tmppath.push_back(i);
        dfs(num - use[i], cnt - 1, sum + i, i);
        tmppath.pop_back();
    }
}

int main() {
    cin >> n >> k >> p;
    for (int i = 1; i <= 20; i++) {
        use[i] = pow(i, p);
        if (use[i] > n) {
            len = i - 1;
            break;
        }
    }
    if (len == 0)
        len = 20;
    dfs(n, k, 0, len);
    if (path.empty()) {
        printf("Impossible");
        return 0;
    }
    printf("%d = %d^%d", n, path[0], p);
    for (int i = 1; i < path.size(); i++)
        printf(" + %d^%d", path[i], p);

    return 0;
}