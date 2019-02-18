#include <iostream>
#include <map>
#include <set>

using namespace std;

int n, m;

map<int, set<int>> chaos;

int main() {
    scanf("%d%d", &n, &m);
    int tmp1, tmp2;
    while (n--) {
        scanf("%d%d", &tmp1, &tmp2);
        chaos[tmp1].insert(tmp2);
        chaos[tmp2].insert(tmp1);
    }
    while (m--) {
        scanf("%d", &tmp1);
        set<int> sset;
        bool flag = false;
        while (tmp1--) {
            scanf("%d", &tmp2);
            for (set<int>::iterator it = chaos[tmp2].begin(); it != chaos[tmp2].end(); it++) {
                if (sset.find(*it) != sset.end()) {
                    flag = true;
                    break;
                }
            }
            sset.insert(tmp2);
        }
        if (!flag)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}