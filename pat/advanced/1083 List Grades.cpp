#include <algorithm>
#include <iostream>

using namespace std;

int n;

struct stu {
    char name[11], id[11];
    int score;
};

bool cmp(stu &a, stu &b) {
    return a.score > b.score;
}
int main() {
    scanf("%d", &n);
    stu stus[n];
    for (int i = 0; i < n; i++) {
        scanf("%s %s %d", stus[i].name, stus[i].id, &stus[i].score);
    }
    sort(stus, stus + n, cmp);
    int minn, maxn;
    scanf("%d%d", &minn, &maxn);
    int r = n - 1;
    while (r >= 0 && stus[r].score < minn)
        r--;
    int l = 0;
    while (l < n && stus[l].score > maxn)
        l++;
    for (int i = l; i <= r; i++)
        printf("%s %s\n", stus[i].name, stus[i].id);
    if (l > r)
        printf("NONE");
    return 0;
}