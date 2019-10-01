#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>

using namespace std;

int n, m;
map<int, int> mmap;

int main() {
    scanf("%d", &n);
    int t1, t2;
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &t1, &t2);
        mmap[t2] = t1;
    }
    int maxn = 0;
    map<int, int>::iterator it = mmap.begin();
    while (it != mmap.end()) {
        map<int, int>::iterator end = mmap.end();
        end--;
        // printf("it: %d %d end: %d %d\n", it->first, it->second, end->first, end->second);
        t1 = it->first;
        mmap[it->first]--;
        if (mmap[it->first] == 0)
            mmap.erase(it->first);
        t2 = end->first;
        mmap[end->first]--;
        if (mmap[end->first] == 0)
            mmap.erase(end->first);
        maxn = max(maxn, t1 + t2);
        it = mmap.begin();
    }

    printf("%d\n", maxn);
    return 0;
}