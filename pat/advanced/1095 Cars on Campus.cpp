// unfinished...
#include <algorithm>
#include <cstring>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

int n, k;
struct node {
    // char id[9];
    string id;
    int tim;
    bool isIn;
};
vector<node> record;
int timToInt(int a, int b, int c) { return a * 3600 + b * 60 + c; }
bool cmp(node &a, node &b) { return a.tim < b.tim; }
struct setComp {
    bool operator()(const char *a, const char *b) { return strcmp(a, b) < 0; }
};

int main() {
    cin >> n >> k;
    scanf("%d%d", &n, &k);
    record.resize(n);
    // char tmp[4];
    string tmp;
    int t1, t2, t3;
    map<string, int> mmap;
    for (int i = 0; i < n; i++) {
        cin >> record[i].id;
        scanf("%d:%d:%d", &t1, &t2, &t3);
        cin >> tmp;
        record[i].tim = timToInt(t1, t2, t3);
        record[i].isIn = tmp[0] == 'i' ? true : false;
    }

    sort(record.begin(), record.end(), cmp);
    for (int i = 0; i < n; i++) {
        if (mmap.find(record[i].id) == mmap.end()) {
            mmap[record[i].id] = record[i].isIn;
        } else if (record[i].isIn == false && mmap[record[i].id]) {
            mmap.erase(record[i].id);
        }
    }
    for (auto i : mmap) {
        cout << i.first;
        printf(" %d\n", i.second);
    }
    int begin = 0;
    while (begin < record.size()) {
        if (mmap.find(record[begin].id) != mmap.end())
            record.erase(record.begin() + begin);
        else
            begin++;
    }
    n = record.size();

    for (int i = 0; i < n; i++)
        printf("%s %d %d\n", record[i].id, record[i].tim, record[i].isIn);

    vector<int> cnt(n);
    cnt[0] = 1;
    for (int i = 1; i < n; i++) {
        cnt[i] = cnt[i - 1];
        if (record[i].isIn)
            cnt[i]++;
        else
            cnt[i]--;
    }
    while (k--) {
        scanf("%d:%d:%d", &t1, &t2, &t3);
        int now = timToInt(t1, t2, t3);
        int i;
        for (i = 0; i < n; i++)
            if (record[i].tim > now)
                break;

        i--;
        printf("i: %d ", i);
        if (i < 0 || i >= n)
            printf("0\n");
        else
            printf("%d\n", cnt[i]);
    }
    return 0;
}