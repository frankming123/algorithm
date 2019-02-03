#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

vector<int> dis(100000);
vector<int> path(100000);
int n, m, cycle;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> dis[i];
        cycle += dis[i];
    }

    for (int i = 1; i < n; i++)
        path[i] = path[i - 1] + dis[i - 1];

    cin >> m;
    while (m--) {
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        if (tmp1 > tmp2)
            swap(tmp1, tmp2);
        tmp1--;
        tmp2--;
        cout << min((path[tmp2] - path[tmp1]), cycle - (path[tmp2] - path[tmp1])) << endl;
    }
    return 0;
}