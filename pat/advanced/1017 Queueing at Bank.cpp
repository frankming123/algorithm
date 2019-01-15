/*
1. customers who comes early then 17:00:01 all can service
2. service more than 1 hour should be 1 hour
*/
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct custom {
    int time;
    int cost;
};

bool isEarlier(custom &a, custom &b) { return a.time < b.time; }

int posOfWindows(vector<int> &window) {
    int minw = window[0];
    for (int i = 0; i < window.size(); i++)
        minw = window[i] < minw ? window[i] : minw;
    for (int i = 0; i < window.size(); i++)
        if (window[i] == minw)
            return i;
}

void print(vector<custom> &c) {
    for (int i = 0; i < c.size(); i++)
        printf("time: %d cost: %d\n", c[i].time, c[i].cost);
}

int main(int argc, char const *argv[]) {
    int n, k;
    cin >> n >> k;

    vector<custom> c;
    int tmp1, tmp2, tmp3, tmp4, tmp;
    for (int i = 0; i < n; i++) {
        scanf("%d:%d:%d %d", &tmp1, &tmp2, &tmp3, &tmp4);
        tmp = tmp1 * 3600 + tmp2 * 60 + tmp3;
        if (tmp > 61200)
            continue;
        c.push_back(custom{tmp, (tmp4 > 60 ? 60 : tmp4) * 60});
    }
    sort(c.begin(), c.end(), isEarlier);
    // print(c);

    vector<int> window(k, 28800);
    int total = 0;

    for (int i = 0; i < c.size(); i++) {
        int pos = posOfWindows(window);
        // printf("pos: %d time: %d\n", pos, window[pos]);
        if (window[pos] > c[i].time) {
            total += window[pos] - c[i].time;
            window[pos] += c[i].cost;
        } else {
            window[pos] = c[i].time + c[i].cost;
        }
    }

    if (c.size() == 0)
        printf("0.0\n");
    else
        printf("%.1f\n", double(total) / c.size() / 60);
    return 0;
}
