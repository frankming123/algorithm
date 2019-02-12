#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

int main() {
    int n;
    int m;
    int num;
    scanf("%d", &n);
    vector<unordered_set<int>> sets(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &m);
        while (m--) {
            scanf("%d", &num);
            sets[i].insert(num);
        }
    }
    int k;
    scanf("%d", &k);
    int set1, set2;
    while (k--) {
        scanf("%d%d", &set1, &set2);
        set1--;
        set2--;
        int sample = sets[set1].size();
        //unordered_set<int> sample = sets[set1];
        for (unordered_set<int>::iterator it = sets[set2].begin(); it != sets[set2].end(); it++) {
            //sample.insert(*it);
            if (sets[set1].find(*it) == sets[set1].end())
                sample++;
        }
        printf("%.1f%%\n", 100 * float(sets[set1].size() + sets[set2].size() - sample) / sample);
    }
    return 0;
}