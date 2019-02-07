#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

struct list {
    int addr;
    int val;
    int next;
};

bool cmp(list &a, list &b) {
    return a.val < b.val;
}

int main() {
    int n, root, tmp;
    cin >> n >> root;
    map<int, list> mymap;
    for (int i = 0; i < n; i++) {
        int tmp1, tmp2, tmp3;
        cin >> tmp1 >> tmp2 >> tmp3;
        mymap[tmp1] = list{tmp1, tmp2, tmp3};
    }
    vector<list> array;
    int now = root;
    while (now != -1) {
        array.push_back(mymap[now]);
        now = mymap[now].next;
    }

    sort(array.begin(), array.end(), cmp);
    if (array.size() == 0) {
        printf("0 -1\n");
        return 0;
    }
    printf("%d %05d\n", array.size(), array[0].addr);
    for (int i = 0; i < array.size(); i++) {
        if (i + 1 == array.size())
            printf("%05d %d -1\n", array[i].addr, array[i].val);
        else
            printf("%05d %d %05d\n", array[i].addr, array[i].val, array[i + 1].addr);
    }

    return 0;
}