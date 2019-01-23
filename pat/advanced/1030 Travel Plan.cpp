#include <iostream>
#include <map>
#include <stack>
#include <vector>

using namespace std;

struct use {
    int d = -1;
    int c;
};

int n, m, s, d;
vector<map<int, use>> path(500);
// vector<vector<use>> path(500, vector<use>(500));
vector<int> passed(500, 0);

int maxdistance = 1 << 31 - 1, maxcost = 1 << 31 - 1;
stack<int> trace, ftrace;
// vector<int> trace, ftrace;

void run(int now, int distance, int cost) {
    // printf("now:%d distance:%d cost:%d\n", now, distance, cost);
    passed[now] = 1;
    trace.push(now);
    // trace.push_back(now);
    if (now == d) {
        if (distance < maxdistance) {
            maxdistance = distance;
            maxcost = cost;
            ftrace = trace;
        } else if (distance == maxdistance && cost < maxcost) {
            maxcost = cost;
            ftrace = trace;
        }
        passed[now] = 0;
        trace.pop();
        // trace.pop_back();
        return;
    }
    for (map<int, use>::iterator it = path[now].begin(); it != path[now].end();
         it++) {
        if (passed[it->first])
            continue;
        run(it->first, distance + it->second.d, cost + it->second.c);
    }
    // for (int i = 0; i < n; i++) {
    //     if (passed[i] || path[now][i].d == -1)
    //         continue;
    //     run(i, distance + path[now][i].d, cost + path[now][i].c);
    // }
    passed[now] = 0;
    trace.pop();
    // trace.pop_back();
}

int main(int argc, char const *argv[]) {
    cin >> n >> m >> s >> d;
    int city1, city2, distance, cost;
    for (int i = 0; i < m; i++) {
        cin >> city1 >> city2 >> distance >> cost;
        path[city1][city2] = use{distance, cost};
        path[city2][city1] = use{distance, cost};
    }
    run(s, 0, 0);
    vector<int> res;
    while (!ftrace.empty()) {
        res.insert(res.begin(), ftrace.top());
        ftrace.pop();
    }

    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << maxdistance << " " << maxcost << endl;
    return 0;
}
