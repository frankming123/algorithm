#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

struct richer {
    char name[9];
    int age, money;
};

bool cmp(richer &a, richer &b) {
    if (a.money > b.money)
        return true;
    if (a.money == b.money && a.age < b.age)
        return true;
    if (a.money == b.money && a.age == b.age)
        return strcmp(a.name, b.name) < 0;
    return false;
}

int main() {
    //std::ios::sync_with_stdio(false);
    int n, k;
    scanf("%d%d\n", &n, &k);
    vector<richer> lists(n);
    for (int i = 0; i < n; i++)
        scanf("%s %d %d\n", lists[i].name, &lists[i].age, &lists[i].money);
    sort(lists.begin(), lists.end(), cmp);

    for (int i = 0; i < k; i++) {
        int m, amin, amax;
        scanf("%d %d %d", &m, &amin, &amax);

        printf("Case #%d:\n", i + 1);
        int count = 0;
        for (int j = 0; j < n; j++)
            if (count < m && lists[j].age >= amin && lists[j].age <= amax) {
                printf("%s %d %d\n", lists[j].name, lists[j].age, lists[j].money);
                count++;
            }

        if (count == 0)
            printf("None\n");
    }
    return 0;
}