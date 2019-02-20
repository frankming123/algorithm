#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n, k;

int cnt[50001];
struct node {
    int val, cnt;
};

vector<node> rec;

bool cmp(node &a, node &b) {
    if (a.cnt == b.cnt)
        return a.val < b.val;
    return a.cnt > b.cnt;
}

int main() {
    cin >> n >> k;
    int now;
    while (n--) {
        cin >> now;
        if (rec.size() != 0) {
            cout << now << ":";
            for (int i = 0; i < rec.size(); i++)
                cout << " " << rec[i].val;
            cout << endl;
        }

        cnt[now]++;
        bool flag = false;
        for (int i = 0; i < rec.size(); i++)
            if (rec[i].val == now) {
                rec[i].cnt++;
                flag = true;
            }
        if (flag)
            sort(rec.begin(), rec.end(), cmp);
        else {
            rec.push_back(node{now, cnt[now]});
            sort(rec.begin(), rec.end(), cmp);
            if (rec.size() > k)
                rec.resize(k);
        }
    }
    return 0;
}