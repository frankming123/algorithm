#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

int couple[100000];

int main() {
    fill(couple, couple + 100000, -1);
    int n;
    cin >> n;
    int t1, t2;
    while (n--) {
        cin >> t1 >> t2;
        couple[t1] = t2;
        couple[t2] = t1;
    }
    cin >> n;
    vector<int> single;
    set<int> query;
    for (int i = 0; i < n; i++) {
        cin >> t1;
        query.insert(t1);
    }
    for (set<int>::iterator it = query.begin(); it != query.end(); it++) {
        if (couple[*it] == -1)
            single.push_back(*it);
        else if (query.find(couple[*it]) == query.end())
            single.push_back(*it);
    }

    sort(single.begin(), single.end());
    cout << single.size() << endl;
    for (int i = 0; i < single.size(); i++) {
        if (i != 0)
            cout << " ";
            printf("%05d",single[i]);
    }
    return 0;
}