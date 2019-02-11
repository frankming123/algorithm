#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<vector<int>> res;
int np, ng;
vector<int> win;

void run(vector<int> &qu) {
    res.insert(res.begin(), vector<int>());
    for (int i = 0; i < qu.size(); i += ng) {
        int maxn = 0;
        int r = i + ng > qu.size() ? qu.size() : i + ng;
        for (int j = i; j < r; j++)
            maxn = qu[j] > maxn ? qu[j] : maxn;
        for (int j = i; j < r; j++) {
            if (qu[j] == maxn)
                win.push_back(qu[j]);
            else
                res[0].push_back(qu[j]);
        }
    }
    swap(qu, win);
    win.clear();
    if (qu.size() > 1)
        run(qu);
    else if (qu.size() == 1)
        res.insert(res.begin(), vector<int>(1, qu[0]));
}

int main() {
    cin >> np >> ng;
    int mice[np];
    int No[1000];
    for (int i = 0; i < np; i++) {
        cin >> mice[i];
        No[mice[i]] = i;
    }

    vector<int> qu(np);
    for (int i = 0; i < np; i++) {
        int tmp;
        cin >> tmp;
        qu[i] = mice[tmp];
    }

    run(qu);

    int count = 1;
    int mices[np];
    for (int i = 0; i < res.size(); i++) {
        int tmp = count;
        for (int j = 0; j < res[i].size(); j++) {
            mices[No[res[i][j]]] = tmp;
            count++;
        }
    }
    for (int i = 0; i < np; i++) {
        if (i != 0)
            cout << " ";
        cout << mices[i];
    }
    // for (int i = 0; i < res.size(); i++) {
    //     for (int j = 0; j < res[i].size(); j++)
    //         cout << res[i][j] << " ";
    //     cout << endl;
    // }
    return 0;
}