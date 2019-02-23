#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

struct node {
    char name[9];
    int height;
};
bool cmp(node &a, node &b) {
    if (a.height == b.height)
        return strcmp(a.name, b.name) > 0;
    return a.height < b.height;
}
int n, k;
vector<node> v;
vector<vector<char *>> res;

int main() {
    scanf("%d%d", &n, &k);
    v.resize(n);
    for (int i = 0; i < n; i++)
        scanf("%s%d", v[i].name, &v[i].height);
    sort(v.begin(), v.end(), cmp);

    int col = n / k;
    for (int i = 0; i < v.size(); i += col) {
        res.push_back(vector<char *>());
        int row = i / col;
        if (row == k - 1)
            col = v.size() - i;

        int j = i + col - 1;
        bool flag = false;
        while (j >= i) {
            res[row].insert(flag ? res[row].begin() : res[row].end(), v[j].name);
            flag = !flag;
            j--;
        }
    }
    for (int i = res.size() - 1; i >= 0; i--) {
        for (int j = 0; j < res[i].size(); j++) {
            if (j != 0)
                printf(" ");
            printf("%s", res[i][j]);
        }
        printf("\n");
    }
    return 0;
}