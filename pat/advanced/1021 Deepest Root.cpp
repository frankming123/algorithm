#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

int n;
vector<set<int>> array(10001, set<int>());
vector<int> passed(10001, 0);
vector<int> levels(10001, 0);

void clearPassed() {
    for (int i = 1; i <= n; i++)
        passed[i] = 0;
}

int maxlevel = 0;
vector<int> roots;

void run(int now, int level) {
    // printf("now: %d level: %d\n", now, level);
    passed[now] = 1;
    if (maxlevel < level) {
        roots.clear();
        maxlevel = level;
        roots.push_back(now);
    } else if (maxlevel == level) {
        roots.push_back(now);
    }
    for (int i = 1; i <= n; i++) {
        if (passed[i] == 0 && array[now].count(i) == 1)
            run(i, level + 1);
    }
}

int main(int argc, char const *argv[]) {
    std::ios::sync_with_stdio(false);
    cin >> n;
    int tmp1, tmp2;
    for (int i = 0; i < n - 1; i++) {
        cin >> tmp1 >> tmp2;
        array[tmp1].insert(tmp2);
        array[tmp2].insert(tmp1);
    }

    int component = 0;
    for (int i = 1; i <= n; i++) {
        if (passed[i] == 0) {
            run(i, 1);
            component++;
        }
    }
    if (component != 1) {
        printf("Error: %d components\n", component);
        return 0;
    }

    // for (int i = 1; i <= n; i++) {
    //     // printf("i: %d\n", i);
    //     maxlevel = 0;
    //     clearPassed();
    //     run(i, 1);
    //     levels[i] = maxlevel;
    // }
    clearPassed();
    // printf("maxroot: %d\n", maxroot);
    set<int> res;
    for (int i = 0; i < roots.size(); i++)
        res.insert(roots[i]);
    run(roots[0], 1);
    for (int i = 0; i < roots.size(); i++)
        res.insert(roots[i]);

    for (set<int>::iterator i = res.begin(); i != res.end(); i++)
        printf("%d\n", *i);

    // for (int i = 1; i <= n; i++)
    //     maxlevel = levels[i] > maxlevel ? levels[i] : maxlevel;

    // for (int i = 1; i <= n; i++)
    //     if (levels[i] == maxlevel)
    //         printf("%d\n", i);
    // printf("i: %d level: %d\n", i, levels[i]);

    return 0;
}
