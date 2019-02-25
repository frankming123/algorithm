#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

int n, k;
string root;
map<string, map<string, int>> route;
map<string, int> happy;
vector<string> tmppath, path;
map<string, int> visits;
string goal = "ROM";
int mincost = 99999999, maxha, leastcnt;

void dfs(string now, int happiness, int cost) {
    if (now == goal) {
        if (cost < mincost) {
            mincost = cost;
            path = tmppath;
            maxha = happiness;
            leastcnt = 1;
        } else if (cost == mincost) {
            leastcnt++;
            if (happiness > maxha) {
                maxha = happiness;
                path = tmppath;
            } else if (happiness == maxha && tmppath.size() < path.size()) {
                path = tmppath;
            }
            return;
        }
    }
    for (auto i : route[now]) {
        if (visits[i.first])
            continue;
        visits[i.first] = 1;
        tmppath.push_back(i.first);
        dfs(i.first, happiness + happy[i.first], cost + i.second);
        visits[i.first] = 0;
        tmppath.pop_back();
    }
}

int main() {
    cin >> n >> k >> root;
    happy[root] = 0;
    string s1, s2;
    int tmp;
    for (int i = 1; i < n; i++) {
        cin >> s1 >> tmp;
        happy[s1] = tmp;
        visits[s1] = 0;
    }
    for (int i = 0; i < k; i++) {
        cin >> s1 >> s2 >> tmp;
        route[s1][s2] = tmp;
        route[s2][s1] = tmp;
    }
    tmppath.push_back(root);
    dfs(root, 0, 0);
    cout << leastcnt << " " << mincost << " " << maxha << " " << (maxha / (path.size() - 1)) << endl;
    cout << path[0];
    for (int i = 1; i < path.size(); i++)
        cout << "->" << path[i];
    return 0;
}