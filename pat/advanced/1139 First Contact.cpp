#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

int n, m;

map<int, set<int>> matrix;
set<int> fri1, fri2;

int gender[10000];

struct node {
    int a, b;
};

bool cmp(node &a, node &b) {
    if (a.a == b.a)
        return a.b < b.b;
    return a.a < b.a;
}

int main() {
    scanf("%d%d", &n, &m);
    int t1, t2;
    string s1, s2;
    while (m--) {
        // scanf("%d%d", &t1, &t2);
        cin >> s1 >> s2;
        t1 = abs(stoi(s1));
        t2 = abs(stoi(s2));
        gender[t1] = s1.length() == 4 ? 1 : -1;
        gender[t2] = s2.length() == 4 ? 1 : -1;

        if (matrix.find(t1) == matrix.end())
            matrix[t1] = set<int>();
        if (matrix.find(t2) == matrix.end())
            matrix[t2] = set<int>();
        matrix[t1].insert(t2);
        matrix[t2].insert(t1);
    }

    int k;
    scanf("%d", &k);
    while (k--) {
        // scanf("%d%d", &t1, &t2);
        cin >> s1 >> s2;
        t1 = abs(stoi(s1));
        t2 = abs(stoi(s2));
        int gen1 = s1.length() == 4 ? 1 : -1;
        int gen2 = s2.length() == 4 ? 1 : -1;
        fri1.clear();
        fri2.clear();
        for (set<int>::iterator it = matrix[t1].begin(); it != matrix[t1].end(); it++)
            if (*it != t2 && gen1 * gender[*it] > 0)
                fri1.insert(*it);
        for (set<int>::iterator it = matrix[t2].begin(); it != matrix[t2].end(); it++)
            if (*it != t1 && gen2 * gender[*it] > 0)
                fri2.insert(*it);

        vector<node> v;
        for (set<int>::iterator it1 = fri1.begin(); it1 != fri1.end(); it1++)
            for (set<int>::iterator it2 = matrix[*it1].begin(); it2 != matrix[*it1].end(); it2++)
                if (fri2.find(*it2) != fri2.end())
                    v.push_back(node{*it1, *it2});

        sort(v.begin(), v.end(), cmp);
        printf("%d\n", v.size());
        for (int i = 0; i < v.size(); i++)
            printf("%04d %04d\n", v[i].a, v[i].b);
    }
    return 0;
}