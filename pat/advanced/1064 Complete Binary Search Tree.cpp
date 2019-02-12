#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> nums(1000);

int posOf(int n) {
    int res = 0;
    int i;
    for (i = 0; res + pow(2, i) <= n; i++)
        res += pow(2, i);

    return (res + 1) / 2 + min(n - res, int(pow(2, i - 1)));
}

vector<vector<int>> tree;

void run(int l, int r, int level) {
    if (r <= l)
        return;
    int pos = posOf(r - l) + l - 1;
    //printf("posOf: %d pos: %d l: %d r: %d\n", posOf(r - l), pos, l, r);
    if (level >= tree.size())
        tree.push_back(vector<int>());
    tree[level].push_back(nums[pos]);
    run(l, pos, level + 1);
    run(pos + 1, r, level + 1);
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    sort(nums.begin(), nums.begin() + n);

    run(0, n, 0);
    for (int i = 0; i < tree.size(); i++) {
        for (int j = 0; j < tree[i].size(); j++) {
            if (i != 0 || j != 0)
                cout << " ";
            cout << tree[i][j];
        }
    }

    return 0;
}